CXXFLAGS=-ggdb -std=c++20 -Wall -Wextra -Werror -Wfatal-errors -pedantic

all: execute

execute: dijkstras_main.o dijkstras.o
	g++  $(CXXFLAGS)  dijkstras_main.o dijkstras.o  -o execute

src/dijkstras_main.o: dijkstras_main.cpp
	g++  $(CXXFLAGS)  dijkstras_main.cpp   -c   dijkstras_main

src/dijkstras.o: dijkstras.cpp
	g++  $(CXXFLAGS)  dijkstras.cpp   -c   dijkstras

clean:
	rm dijkstras_main.o dijkstras.o execute