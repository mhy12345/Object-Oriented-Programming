all:main.exe clean
main.exe:main.o Hen.o Nest.o Egg.o Hen.h Nest.h Egg.h
	g++ main.o Hen.o Nest.o Egg.o -o main.exe
main.o:main.cpp Hen.h Nest.h Egg.h
	g++ -c main.cpp -o main.o
Hen.o:Hen.cpp Hen.h
	g++ -c Hen.cpp -o Hen.o
Nest.o:Nest.cpp Nest.h Hen.h
	g++ -c Nest.cpp -o Nest.o
Egg.o:Egg.cpp Egg.h Nest.h Hen.h
	g++ -c Egg.cpp -o Egg.o
clean:
	del *.o
