#!/bin/sh

rm test.o
g++ -o test.o solver.cpp matrix.cpp
./test.o

