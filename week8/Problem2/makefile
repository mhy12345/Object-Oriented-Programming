cc = g++ -g

target : Matrix.o main.o
	$(cc) -o main Matrix.o main.o

Matrix.o : Matrix.cpp main.cpp

main.o : main.cpp
