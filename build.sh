#!/bin/sh

rm -rf ./output
mkdir output
cd ./output
g++ -c ../implementation/*.c
cd ..
ar rcs lib_mylib.a output/*
