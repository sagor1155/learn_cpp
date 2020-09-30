#!/bin/bash

g++ -c main.cpp
# g++ -c print.cpp
# g++ -c factorial.cpp
# g++ -c multiply.cpp
# g++ -o main main.o print.o factorial.o multiply.o
g++ -o main main.o
./main
