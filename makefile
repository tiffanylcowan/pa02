#makefile

all: prog1.out

prog1.out: quash.cpp
    g++ -o prog1.out quash.cpp -std=c++11


