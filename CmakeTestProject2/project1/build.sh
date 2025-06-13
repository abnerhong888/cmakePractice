#!/bin/bash

mkdir build
cd build

cmake ..

cmake_result=$?
echo
echo "cmake result = " $cmake_result
echo
if [ $cmake_result != 0 ]; then 
    echo "cmake failed"
    exit
fi

make 

make_result=$?
echo
echo "make result = " $make_result
echo
if [ $make_result != 0 ]; then 
    echo "make failed"
    exit
fi

echo
echo "build success"