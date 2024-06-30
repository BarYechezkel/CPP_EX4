

CC = g++ -g -Wall
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system
.PHONY: all clean test

all: tree

tree: main.o
	$(CC) -o $@ $^ $(SFML_LIBS)

main.o: main.cpp Node.hpp Tree.hpp
	$(CC) -c -o $@ $<


test: 
	

clean:
	rm -f main main.o