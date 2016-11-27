#include "../include/Graph.h"
extern std::vector<int> highest;

Graph::Graph(int V)
{
        this->V = V;
        adj = new std::list<int>[V];
}

void Graph::DFSUtil(int v, bool visited[])
{

    visited[v] = true;
    //std::cout << v << " ";

    std::list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
        {
            cnt++;
            DFSUtil(*i, visited);
        }
}

Graph Graph::getTranspose()
{
    Graph g(V);
    for (int v=0;v < V; v++)
    {
        std::list<int>::iterator i;
        for (i=adj[v].begin(); i != adj[v].end(); ++i)
        {
            g.adj[*i].push_back(v);
        }
    }
    return g;
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::fillOrder(int v, bool visited[], std::stack<int> &Stack)
{
    visited[v] = true;

    std::list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            fillOrder(*i, visited, Stack);

    Stack.push(v);
}

// The main function that finds and prints all strongly connected
// components
void Graph::printSCCs()
{
    std::stack<int> Stack;

    // Mark all the vertices as not visited (For first DFS)
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    // Fill vertices in stack according to their finishing times
    for(int i = 0; i < V; i++)
        if(visited[i] == false)
            fillOrder(i, visited, Stack);

    // Create a reversed graph
    Graph gr = getTranspose();

    // Mark all the vertices as not visited (For second DFS)
    for(int i = 0; i < V; i++)
        visited[i] = false;

    // Now process all vertices in order defined by Stack
    while (Stack.empty() == false)
    {
        // Pop a vertex from stack
        int v = Stack.top();
        Stack.pop();

        // Print Strongly connected component of the popped vertex
        if (visited[v] == false)
        {
            gr.DFSUtil(v, visited);
            if (cnt >= 2)
            {
                highest.push_back(cnt);
            }
            cnt = 0;
            //std::cout << std::endl;
        }
    }
}
