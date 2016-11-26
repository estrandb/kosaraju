#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

#include <string>
#include <sstream>

static const int WIDTH = 3;
static const int HEIGHT = 5105043;

using namespace std;

void printvertices(vector<vector<int> >& graph)
{
	for (int i = 0 ; i < 200 ; i++)
	{
		for (int j = 0 ; j < graph[i].size() ; j++)
		{
			cout << graph[i][j] << " ";
		}
		cout << '\n';
	}
}

void readfile(vector<vector<int> >& graph)
{
	string line;


	ifstream file("./SCC.txt");
	while(getline(file,line))
    {
        stringstream lineStream(line);
        vector<int> lineData;


        int value;
        while (lineStream >> value)
        {
            lineData.push_back(value);
        }
        if (graph.size() > 0)
        {
            int linedatatest = lineData[0] - 1;
            bool graphtest = graph.at(1).empty();
            if (!graph[lineData[0] - 1].empty())
            {
                graph[lineData[0] - 1].push_back(lineData[1]);
            }
            else
            {
                graph[lineData[0] - 1].push_back(lineData[0]);
                graph[lineData[0] - 1].push_back(lineData[1]);
                vector<int> newline;
                graph.push_back(newline);
            }
        }
        else
        {
            graph.push_back(lineData);
            vector<int> newline;
            graph.push_back(newline);
        }
    }

	//while (getline(file,vector))
	//{

	//}
	return;
}

int dfsloop(vector<vector<int> >& graph)
{
	static int t = 0;
	static int s = NULL;


	return 1;
}

int main()
{
	vector<vector<int> > graph;

	readfile(graph);
	dfsloop(graph);
	printvertices(graph);

	return 1;
}
