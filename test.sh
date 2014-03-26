#!/bin/sh

rm test.o
g++ -o test.o main.cpp matrix.cpp
./test.o


