#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "heap.h"

using namespace std;
using namespace heap;

/**
 * Default constructor.
 */
Heap::Heap() {}

/**
 * Primary constructor
 * @param vertexArray
 * @param heapCapacity
 */
Heap::Heap(int *vertexArray, int heapCapacity)
{
    capacity = heapCapacity;
    heapSize = 0;
    heapArr = new node[capacity];

    //Populate heap with vertex elements.
    for (int i = 0; i < heapCapacity; i++)
    {
        node newNode;
        newNode.vertex = vertexArray[i];
        heapArr[i] = newNode;
    }

    //Heapify array.

}

/**
 * Insert an element into the minHeap.
 * @param k
 */
void Heap::insert(int k)
{
    if(heapSize == capacity)
    {
        return;
    }

    heapSize = heapSize + 1;
    int i = heapSize - 1;
    node newNode;
    newNode.vertex = k;
    heapArr[i] = newNode;

    while (i != 0 && heapArr[parent(i)].vertex > heapArr[i].vertex)
    {
        swap(&heapArr[i], &heapArr[parent(i)]);
        i = parent(i);
    }

}