#!/bin/bash

FILEPATH="A.cpp"
echo Build file %FILEPATH%
echo
g++ %FILEPATH% -o out && ./out < inp.txt

# clear
rm -f *.exe