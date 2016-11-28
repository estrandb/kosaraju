#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <list>
#include <stack>
#include <vector>

class Graph
{
    int V;
    std::list<int> *adj;

    void fillOrder(int v, bool visited[], std::stack<int> &Stack);
    void DFSUtil(int v, bool visited[]);

    public:
        Graph(int V);

        void addEdge(int v, int w);
        void printSCCs();
        Graph getTranspose();
};

#endif // GRAPH_H
