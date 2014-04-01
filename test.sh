#!/bin/sh

rm test.o
g++ -o test.o matrix.cpp solver.cpp main.cpp
./test.o

