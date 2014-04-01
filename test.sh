#!/bin/sh

rm test.o
g++ -o test.o solver.cpp matrix.cpp main.cpp
./test.o

