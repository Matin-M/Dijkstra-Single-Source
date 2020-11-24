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
        Heap(int heapCapacity);

        //Insert into min-heap.
        void insert(node k);

        //Extract min node.
        node extractMin();

        //Decrease a key value for a node.
        void decreaseKey(int i, node newVal);

        //Search heap.
        int searchHeap(int vertex);

        //Return min node.
        node minimum() { return heapArr[0]; }

        //Getter methods.
        node *getHeapArr() { return heapArr; }

        int getCapacity() { return capacity; }

        int getHeapSize() { return heapSize; }

};

#endif