#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <climits>
#include "heap.h"

using namespace std;
using namespace util;

/**
 * Default constructor.
 */
Heap::Heap() {}

/**
 * Primary constructor
 * @param heapCapacity
 */
Heap::Heap(int heapCapacity)
{
    capacity = heapCapacity;
    heapSize = 0;
    heapArr = new node[capacity];
}

/**
 * Insert an element into the minHeap.
 * @param k
 */
void Heap::insert(node k)
{
    if(heapSize == capacity)
    {
        return;
    }

    heapSize = heapSize + 1;
    int i = heapSize - 1;
    heapArr[i] = k;

    while (i != 0 && heapArr[parent(i)].distance > heapArr[i].distance)
    {
        swap(&heapArr[i], &heapArr[parent(i)]);
        i = parent(i);
    }
}

/**
 * Extract minimum element.
 * @return
 */
node Heap::extractMin()
{
    if(heapSize <= 0)
    {
        return node(-1,-1, INT_MAX);
    }

    if(heapSize == 1)
    {
        heapSize--;
        return heapArr[0];
    }

    node min = heapArr[0];
    heapArr[0] = heapArr[heapSize-1];
    heapSize--;
    minHeapify(0);
    return min;
}

/**
 * Decrease a key for a given index.
 * @param i
 * @param newVal
 */
void Heap::decreaseKey(int i, int newVal)
{
    i = searchHeap(i);
    heapArr[i].distance = newVal;
    while(i != 0 && heapArr[parent(i)].distance > heapArr[i].distance)
    {
        swap(&heapArr[i], &heapArr[parent(i)]);
        i = parent(i);
    }
}

/**
 * Min-heapify algorithm that maintains min-heap properties.
 * @param v
 */
void Heap::minHeapify(int v)
{
    int leftNode = left(v);
    int rightNode = right(v);
    int min = v;
    if (leftNode < heapSize && heapArr[leftNode].distance < heapArr[v].distance)
        min = leftNode;
    if (rightNode < heapSize && heapArr[rightNode].distance < heapArr[min].distance)
        min = rightNode;
    if (min != v)
    {
        swap(&heapArr[v], &heapArr[min]);
        minHeapify(min);
    }
}

/**
 * Search the heap.
 * @param vertex
 * @return
 */
int Heap::searchHeap(int vertex)
{
    for(int i = 0; i < capacity; i++)
    {
        if(heapArr[i].vertex == vertex)
        {
            return i;
        }
    }

    return -1;
}
