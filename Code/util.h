#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <climits>

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
        int id;
        int weight;
        struct graphNode* next;

        graphNode()
        {
            id = -1;
            weight = -1;
            next = NULL;
        }

        graphNode(int newId, int newWeight, graphNode* nextNode)
        {
            id = newId;
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