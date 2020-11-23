#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <climits>
#include "util.h"

using namespace std;
using namespace util;

#ifndef GRAPH_H
#define GRAPH_H

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

        //Insert element into graph given node.
        void insertNode(graphNode* newNode, int pos);

        //Insert element into graph given vertex, vertex, and weight.
        void insertGraph(int u, int v, int w);

        //Search graph for specific vertex at given position.
        graphNode** returnNodesAtPos(int v);

        //Return the number of nodes .
        int returnNumNodesAtPos(int v);
};

#endif