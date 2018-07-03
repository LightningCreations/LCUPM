CXX := g++

all: lcupm

lcupm: main.o 
	$(CXX) -g -lncurses main.o

main.o: main.cpp
	$(CXX) -g -c -lncurses main.cpp

run: lcupm
	./lcupm

debug: lcupm
	gdb lcupm
