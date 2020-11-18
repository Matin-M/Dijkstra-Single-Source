#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
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
            distance = -1;
        }

        //Min heap constructor.
        node(int vertexNode, int predNode, int distanceNode)
        {
            vertex = vertexNode;
            pred = predNode;
            distance = distanceNode;
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
    void swap(node *x, node *y)
    {
        node temp = *x;
        *x = *y;
        *y = temp;
    }

}