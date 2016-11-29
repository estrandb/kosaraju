#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

#include <string>
#include <sstream>

using namespace std;

const int NUM_VERTICES = 9;

int finishTimes[NUM_VERTICES];
int leader[NUM_VERTICES];

void printVerts(const vector<vector<int> >& graph)
{
    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph.at(i).size(); j++)
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
    for(int i = 0; i < NUM_VERTICES; i++)
    {
        visited[i] = false;
    }
    return;
}

void dfs(vector<vector<int> >& graph, int i, vector<bool>& visited, int& t, int& s)
{
    visited[i] = true;
    leader[i] = s;
    for (int j = 0; j < graph[i].size(); j++)
    {
        if (!visited[graph[i][j]])
        {
            dfs(graph, graph[i][j], visited, t, s);
        }
    }
    t++;
    finishTimes[i] = t;
}

void dfsLoop(vector<vector<int> >& graph, vector<bool>& visited)
{
    int t = -1;
    int s = 0;
    for (int i = NUM_VERTICES - 1; i >= 0; i--)
    {
        if (!visited[i])
        {
            s = i;
            dfs(graph, i, visited, t, s);
        }
    }
}

int main()
{
    vector<vector<int> > graph;
    vector<vector<int> > revGraph;
    vector<vector<int> > transposeGraph;
    vector<bool> visited;
    for (int i = 0; i < NUM_VERTICES; i++)
    {
        vector<int> vec;

        graph.push_back(vec);
        revGraph.push_back(vec);
        transposeGraph.push_back(vec);

        visited.push_back(false);
    }
    setVisitedFalse(visited);
    string vector;
    //6,3,2,1,0
    ifstream file("./test.txt");
	while (getline(file,vector))
	{
        std::vector<int> lineData;
		stringstream lineStream(vector);
		int value;
		while (lineStream >> value)
		{
			lineData.push_back(value);
		}
		//add to array here
        graph.at(lineData[0] - 1).push_back(lineData[1] - 1);
        revGraph.at(lineData[1] - 1).push_back(lineData[0] - 1);
	}

    printVerts(graph);
	printVerts(revGraph);
    printVerts(transposeGraph);

    dfsLoop(revGraph, visited);

    int z = finishTimes[0];

    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            transposeGraph[finishTimes[i]].push_back(finishTimes[graph[i][j]]);
        }
    }
    printVerts(graph);
	printVerts(revGraph);
    printVerts(transposeGraph);



    return 0;
}
