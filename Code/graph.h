#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <climits>
#include "util.h"

using namespace std;
using namespace util;

class Graph
{
    private:
        //Adjacency list.
        graphNode** adjList;
        //Number of nodes in the graph.
        int numNodes;
        //Number of edges in the graph.
        int numEdges;

    public:
        //Default constructor.
        Graph();

        //Initialize linkedLists.
        Graph(int newNumNodes, int newNumEdges);

};