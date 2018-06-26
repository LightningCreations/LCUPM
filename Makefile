all: lcupm

lcupm: main.o 
  clang -g -lncurses main.o

main.o: main.cpp
  clang -g -c -lncurses main.cpp
