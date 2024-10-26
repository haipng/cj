#!/bin/bash

FILEPATH="/workspaces/cj/lge_cj/LGE_2021_Final/Hiking.cpp"
echo "Build file $FILEPATH"
echo ""
g++ "$FILEPATH" -o out && ./out < inp.txt

# clear
rm -f *.exe