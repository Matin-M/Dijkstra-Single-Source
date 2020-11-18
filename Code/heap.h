#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

namespace heap {

    class Heap {
    private:

        //min-heap struct.
        struct node {
            int vertex;
            int pred;
            int distance;
        };

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
        //Swap nodes.
        void swap(node *x, node *y)
        {
            node temp = *x;
            *x = *y;
            *y = temp;
        }

    public:
        //Default constructor.
        Heap();

        //Overloaded constructor.
        Heap(int *vertexArray, int capacity);

        //Insert into min-heap.
        void insert(int k);

        //Return min node.
        node minimum() { return heapArr[0]; }

        //Extract min node.
        node extractMin();

        //Decrease a key value for a node.
        void decreaseKey(int i, int newVal);


    };
}