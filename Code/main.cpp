#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <climits>
#include "graph.h"
#include "heap.h"
#include "main.h"
#include "util.h"

using namespace std;

int Main::main() {
    //Parse text file.
    string input = "";
    getline(cin, input);
    //Obtain n and m;
    int spaceIndex = input.find(' ');
    int n = stoi(input.substr(0,spaceIndex));
    int m = stoi(input.substr(spaceIndex,input.length()-1));

    //Graph object that maintains graph.
    Graph graph(n,m);

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
        spaceIndex = input.find(' ',4);
        w = stoi(input.substr(spaceIndex,input.length()-1));
        //Insert graphNode into graph.
        graph.insertGraph(u,v,w);
    }

    return 0;
}