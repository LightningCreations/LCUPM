CXX := g++

all: lcupm

lcupm: main.o
	$(CXX) -g -o lcupm main.o -lncurses -ltinfo

main.o: main.cpp
	$(CXX) -g -c main.cpp -lncurses -ltinfo

run: lcupm
	./lcupm

debug: lcupm
	gdb lcupm
