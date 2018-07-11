CXX := g++

all: lcupm

lcupm: main.o
	$(CXX) -g -o lcupm main.o -lcurl

main.o: main.cpp
	$(CXX) -g -c main.cpp

run: lcupm
	./lcupm

debug: lcupm
	gdb lcupm
