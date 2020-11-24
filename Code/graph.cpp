#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <climits>
#include "graph.h"

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

/**
 * Insert a new node into adj list at give position.
 * @param newNode
 * @param pos
 */
void Graph::insertNode(graphNode* newNode, int pos)
{
    if(adjList[pos] == NULL)
    {
        adjList[pos] = newNode;
    }else{
        newNode->next = adjList[pos];
        adjList[pos] = newNode;
    }
}

/**
 * Insert a new edge from u to v with weight w.
 * @param u
 * @param v
 * @param w
 */
void Graph::insertGraph(int u, int v, int w)
{
    graphNode* newGraphNode = new graphNode(u, v, w,NULL);
    insertNode(newGraphNode, u);
}

/**
 * Return the number of nodes at a vertex position.
 * @param v
 * @return
 */
int Graph::returnNumNodesAtPos(int u) {
    //Subtract 1 from u to allow indexing of nodes starting from 1.
    graphNode* head = adjList[u-1];
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head->next;
    }

    return count;
}

/**
 * Return an array containing the nodes at vertex v.
 * @param v
 * @return
 */
graphNode** Graph::returnNodesAtPos(int u)
{
    graphNode** nodeArr;
    int count = returnNumNodesAtPos(u);

    nodeArr = new graphNode*[count];
    graphNode* head = adjList[u-1];
    for(int i = 0; i < count && head != NULL; i++)
    {
        nodeArr[i] = head;
        head = head->next;
    }

    return nodeArr;
}
