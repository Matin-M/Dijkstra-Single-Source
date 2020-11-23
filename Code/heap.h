#include <stdio.h>
#include <stdlib.h>
#include <climits>
#include "util.h"

using namespace std;
using namespace util;

#ifndef HEAP_H
#define HEAP_H

class Heap {

    private:
        //Heap array.
        node *heapArr;
        //Capacity.
        int capacity;
        //Heap size;
        int heapSize;

        //Heapify algorithm that maintains heap properties.
        void minHeapify(int v);

        //Left subnode.
        int left(int index) { return 2 * index + 1; }
        //Right subnode.
        int right(int index) { return 2 * index + 2; }
        //Parent subnode
        int parent(int index) { return (index - 1) / 2; }


    public:
        //Default constructor.
        Heap();

        //Overloaded constructor.
        Heap(node *vertexArray, int capacity);

        //Insert into min-heap.
        void insert(node k);

        //Return min node.
        node minimum() { return heapArr[0]; }

        //Extract min node.
        node extractMin();

        //Decrease a key value for a node.
        void decreaseKey(int i, node newVal);

        //Set distance to inf, and pred to -1 for each node.
        void initSingleSource();

        node *getHeapArr();

        int getCapacity();

        int getHeapSize();

};

#endif