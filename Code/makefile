dijkstra: Heap.o Graph.o Main.o Util.o
	g++ -std=c++11 Heap.o Main.o Util.o Graph.o -o dijkstra

Main.o: Main.cpp
	g++ -std=c++11 -c Main.cpp

Graph.o: Graph.cpp
	g++ -std=c++11 -c Graph.cpp

Util.o: Util.cpp
	g++ -std=c++11 -c Util.cpp

Heap.o: Heap.cpp
	g++ -std=c++11 -c Heap.cpp

clean:
	rm *.o dijkstra