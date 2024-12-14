tsp: main.o graph.o
	g++ -std=c++11 -o tsp main.o graph.o

main.o: main.cpp graph.h graphinterface.h
	g++ -std=c++11 -c main.cpp

graph.o: graph.cpp graph.h graphinterface.h
	g++ -std=c++11 -c graph.cpp

clean:
	rm -f *.o tsp
