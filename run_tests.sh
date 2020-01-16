#!/bin/sh
gcc -o tests */*.c -lcriterion
./tests
rm tests
