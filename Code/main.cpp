#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <climits>
#include "util.h"
#include "graph.h"
#include "heap.h"

using namespace std;

//Graph object.
Graph graph;
//Heap object.
Heap minHeap;
//Set S containing vertices.
node* S;


void Dijkstra(node source)
{
    //Q = V, and initialize heap nodes.
    graphNode** adjList = graph.getAdjList();
    minHeap = Heap(graph.getNumNodes());
    node* minHeapArr = minHeap.getHeapArr();

    //Iterate through the graph, fill min heap with nodes.
    for(int i = 1; i < graph.getNumNodes() + 1; i++)
    {
        //Insert nodes into minHeap.
        node newHeapNode;
        if(i == source.vertex)
        {
            newHeapNode = node(source.vertex, -1, 0);
        }else
        {
            newHeapNode = node(adjList[i]->originalVertex, -1, INT_MAX);
        }
        minHeap.insert(newHeapNode);
    }

    //Set S to empty set via initializing all values to -1.
    S = new node[graph.getNumNodes()];
    for(int i = 0; i < graph.getNumNodes(); i++)
    {
        S[i].vertex = -10;
    }

    int index = 0;
    while(minHeap.getHeapSize() != 0)
    {
        node u = minHeap.extractMin();
        S[index] = u;

        graphNode** adjToU = graph.returnNodesAtPos(u.vertex);
        //Start from one to skip vertex u.
        for(int i = 0; i < graph.returnNumNodesAtPos(u.vertex); i++)
        {
            graphNode* v = adjToU[i];
            int indexV = minHeap.searchHeap(v->vertex);
            if(indexV == -1)
            {
                continue;
            }
            node vNode = minHeapArr[indexV];
            if(vNode.distance > (u.distance + v->weight))
            {
                minHeap.decreaseKey(v->vertex, u.distance + v->weight);
                minHeapArr[indexV].pred = u.vertex;
            }

        }
        index++;
    }


}

int main()
{

    //Parse text file.
    string input = "";
    getline(cin, input);
    //Obtain n and m;
    int spaceIndex = input.find(' ');
    int n = stoi(input.substr(0,spaceIndex));
    int m = stoi(input.substr(spaceIndex,input.length()-1));

    //Graph object that maintains graph.
    graph = Graph(n,m);

    //Store edges and vertecies into graph.
    int u;
    int v;
    int w;
    for(int i = 0; i < m; i++)
    {
        //Parse input line and extract u, v, and w.
        getline(cin, input);
        spaceIndex = input.find(' ');
        u = stoi(input.substr(0,spaceIndex));
        v = stoi(input.substr(spaceIndex,input.length()-1));
        spaceIndex = input.find(' ',spaceIndex+1);
        w = stoi(input.substr(spaceIndex,input.length()-1));
        //Insert graphNode into graph.
        graph.insertGraph(u,v,w);
    }

    node test = node(3,-1,0);
    Dijkstra(test);

    for(int i = 0; i < graph.getNumNodes(); i++)
    {
        cout << S[i].vertex << ";" << S[i].distance << endl;
    }


    return 0;
}