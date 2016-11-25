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
	string vector;

	ifstream file("/home/sig/projects/prog4/SCC.txt");
	while (getline(file,vector))
	{
		if (vector.at(0) == graph.last[0])
		{
			graph.last.push_back()
		}
	}
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