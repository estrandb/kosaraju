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

const int NUM_VERTICES = 12;
int t = 0;
int s = 0;

void printVerts(const vector<vector<int> >& graph)
{
    for (int i = 0; i < NUM_VERTICES; i++)
    {
        for (int j = 0; j < graph.at(i).size(); j++)
        {
            cout << graph.at(i).at(j) << " ";
        }
        cout << endl;
    }
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

void dfsReverse(vector<vector<int> >& graph)
{

}

int main()
{
    vector<vector<int> > graph;
    vector<bool> visited;
    for (int i = 0; i < NUM_VERTICES; i++)
    {
        vector<int> vec;
        graph.push_back(vec);

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
	}
	printVerts(graph);



    return 0;
}
