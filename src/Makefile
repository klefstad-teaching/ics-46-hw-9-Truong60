CXXFLAGS=-ggdb -std=c++20 -Wall -Wextra -Werror -Wfatal-errors -pedantic

all: execute

execute: ladder_main.o ladder.o
	g++  $(CXXFLAGS)  ladder_main.o ladder.o  -o execute

src/ladder_main.o: ladder_main.cpp
	g++  $(CXXFLAGS)  ladder_main.cpp   -c   ladder_main

src/ladder.o: ladder.cpp
	g++  $(CXXFLAGS)  ladder.cpp   -c   ladder

clean:
	rm ladder_main.o ladder.o execute