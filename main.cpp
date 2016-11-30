#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>

#include <string>
#include <sstream>

#define VERBOSE 0

using namespace std;

const uint32_t NUM_VERTICES = 875714;

uint32_t finishTimes[NUM_VERTICES];
uint32_t leader[NUM_VERTICES];

uint32_t cnt;
vector<uint32_t> highest;

bool myfunction (int i,int j) { return (i<j); }

void printVerts(const vector<vector<uint32_t> >& graph)
{
    for (uint32_t i = 0; i < graph.size(); i++)
    {
        for (uint32_t j = 0; j < graph.at(i).size(); j++)
        {
            cout << graph.at(i).at(j) << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
    return;
}

void setVisitedFalse(vector<bool>& visited)
{
    for(uint32_t i = 0; i < NUM_VERTICES; i++)
    {
        visited[i] = false;
    }
    return;
}

void dfs(vector<vector<uint32_t> >& graph, uint32_t i, vector<bool>& visited, int64_t& t, uint32_t& s)
{
    visited[i] = true;
    for (uint32_t j = 0; j < graph[i].size(); j++)
    {
        if (!visited[graph[i][j]])
        {
            dfs(graph, graph[i][j], visited, t, s);
            cnt++;
        }
    }
    t++;
    finishTimes[i] = t;
}

void dfsLoop(vector<vector<uint32_t> >& graph, vector<bool>& visited)
{
    int64_t t = -1;
    uint32_t s = 0;
    for (int64_t i = NUM_VERTICES - 1; i >= 0; i--)
    {
        cnt = 0;
        if (!visited[i])
        {
            s = i;
            cnt = 1;
            leader[i] = s;
            dfs(graph, i, visited, t, s);
        }
        highest.push_back(cnt);
        sort(highest.begin(), highest.end(), myfunction);
        if (highest.size() > 5)
        {
            highest.erase(highest.begin());
        }
    }
}

int main()
{
    vector<vector<uint32_t> > graph;
    vector<vector<uint32_t> > revGraph;
    vector<vector<uint32_t> > transposeGraph;
    vector<bool> visited;
    for (uint32_t i = 0; i < NUM_VERTICES; i++)
    {
        vector<uint32_t> vec;

        graph.push_back(vec);
        revGraph.push_back(vec);
        transposeGraph.push_back(vec);

        visited.push_back(false);
    }
    setVisitedFalse(visited);
    string vector;
    //6,3,2,1,0
    ifstream file("./SCC.txt");
	while (getline(file,vector))
	{
        std::vector<uint32_t> lineData;
		stringstream lineStream(vector);
		uint32_t value;
		while (lineStream >> value)
		{
			lineData.push_back(value);
		}
		//add to array here
        graph.at(lineData[0] - 1).push_back(lineData[1] - 1);
        revGraph.at(lineData[1] - 1).push_back(lineData[0] - 1);
	}

    #if VERBOSE

    printVerts(graph);
	printVerts(revGraph);
    printVerts(transposeGraph);

    #endif

    dfsLoop(revGraph, visited);

    for (uint32_t i = 0; i < graph.size(); i++)
    {
        for (uint32_t j = 0; j < graph[i].size(); j++)
        {
            transposeGraph[finishTimes[i]].push_back(finishTimes[graph[i][j]]);
        }
    }

    setVisitedFalse(visited);

    //reset highest from first dfs
    highest.clear();

    //reset leaders from first dfs
    for (uint32_t i = 0; i < NUM_VERTICES; i++)
    {
        leader[i] = 0;
    }

    dfsLoop(transposeGraph, visited);

    for (std::vector<uint32_t>::iterator it = highest.begin(); it != highest.end(); ++it)
    {
        cout << *it << endl;
    }

    /*
    for (uint32_t i = 0; i < NUM_VERTICES; i++)
    {
        cout << leader[i] << endl;
    }
    */

    #if VERBOSE

    printVerts(graph);
	printVerts(revGraph);
    printVerts(transposeGraph);

    #endif


    return 0;
}
