all : prog

prog : tools.o solvers.o main.o tests.o
	g++ tools.o solvers.o main.o tests.o -o prog

tools.o : tools.cpp
	g++ -c tools.cpp -o tools.o

tests.o : tests.cpp
	g++ -c tests.cpp -o tests.o

main.o : main.cpp
	g++ -c main.cpp -o main.o

solvers.o : solvers.cpp
	g++ -c solvers.cpp -o solvers.o
