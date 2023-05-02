connect: main.o board.o
	g++ main.o board.o -o connect.out -Wall -pedantic

main.o: main.cpp
	g++ -c -o main.o main.cpp -Wall -pedantic

board.o: board.cpp
	g++ -c -o board.o board.cpp -Wall -pedantic

