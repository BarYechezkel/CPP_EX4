
CC = g++ -g -Wall
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system
.PHONY: all clean test

all: tree test

tree: main
	./main

main: main.o Complex.o
	$(CC) -o $@ $^ $(SFML_LIBS)

main.o: main.cpp Complex.hpp Node.hpp Tree.hpp
	$(CC) -c -o $@ main.cpp

Complex.o: Complex.cpp Complex.hpp
	$(CC) -c -o Complex.o Complex.cpp

test: 
	

clean:
	rm -f main main.o