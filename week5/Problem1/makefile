cc = g++ -g
exe = main
target: $(exe)

main : main.o graph.o point.o mst.o
	$(cc) main.o graph.o point.o mst.o -o main

graph.o : graph.cpp graph.h

point.o : point.cpp point.h

mst.o : mst.cpp mst.h

main.o : main.cpp

clear : 
	rm *.o $(exe)
