#!/bin/bash

export LD_PRELOAD="./mymalloc.so";\
echo $LD_PRELOAD;\
./intr 10 100 1000