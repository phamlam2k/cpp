#!/bin/bash
FILE=${1:-main.cpp}
BIN="${FILE%.cpp}"

echo "=== Compiling $FILE ==="
g++ -O2 -o "$BIN" "$FILE"

if [ $? -ne 0 ]; then
    echo "Compile failed!"
    exit 1
fi

echo "=== Running with input.txt ==="
./"$BIN" < input.txt
