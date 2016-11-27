#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

#include <string>
#include <sstream>

#include "include/Graph.h"

static const int WIDTH = 3;
static const int HEIGHT = 5105043;

using namespace std;

std::vector<int> highest;

int main()
{
	//Graph g(875714);
	Graph g(12);

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

        g.addEdge(lineData[0],lineData[1]);
	}


    cout << "Following are strongly connected components in "
            "given graph \n";
    g.printSCCs();

    for (int i=0; i<highest.size() ; i++)
    {
        cout << "highest[" << i << "]: " << highest[i] << endl;
    }

    return 0;
}
