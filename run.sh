#!/bin/bash

g++ -std=c++23 ./src/main.cpp ./src/grid.cpp ./src/simulation.cpp -o game_of_life -lraylib -lm 
./game_of_life