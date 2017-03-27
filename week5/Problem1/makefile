cc = g++ -g
exe = main
target: $(exe)

main : main.o graph.o point.o
	$(cc) main.o graph.o point.o -o main

graph.o : graph.cpp graph.h
	$(cc) main.cpp -o main.o

point.o : point.cpp point.h

main.o : main.cpp

clear : 
	rm *.o $(exe)
