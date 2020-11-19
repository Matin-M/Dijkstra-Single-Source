#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <climits>

#ifndef UTIL_H
#define UTIL_H

using namespace std;

namespace util
{
    //min-heap struct.
    struct node {
        int vertex;
        int pred;
        int distance;
        //Default constructor.
        node()
        {
            vertex = -1;
            pred = -1;
            distance = INT_MAX;
        }

        //Min heap constructor.
        node(int vertexNode, int predNode, int distanceNode)
        {
            vertex = vertexNode;
            pred = predNode;
            distance = distanceNode;
        }
    };

    //Graph node struct.
    struct graphNode
    {
        int originalVertex;
        int vertex;
        int weight;
        struct graphNode* next;

        //GraphNode default constructor.
        graphNode()
        {
            originalVertex = -1;
            vertex = -1;
            weight = -1;
            next = NULL;
        }
        //GraphNode
        graphNode(int originalVertexV, int newVertex, int newWeight, graphNode* nextNode)
        {
            originalVertex = originalVertexV;
            vertex = newVertex;
            weight = newWeight;
            next = nextNode;
        }
    };

    //Swap ints.
    static void swap(int *x, int *y)
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }

    //Swap nodes.
    static void swap(node *x, node *y)
    {
        node temp = *x;
        *x = *y;
        *y = temp;
    }

}

#endif