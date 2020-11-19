#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <climits>
#include "graph.h";

using namespace std;
using namespace util;

/**
 * Default constructor.
 */
Graph::Graph()
{
    adjList = NULL;
    numNodes = 0;
    numEdges = 0;
}

/**
 * Constructor used for initializing adj list.
 * @param newNumNodes
 * @param newNumEdges
 */
Graph::Graph(int newNumNodes, int newNumEdges)
{
    numNodes = newNumNodes;
    numEdges = newNumEdges;
    adjList = new graphNode*[numNodes];
}