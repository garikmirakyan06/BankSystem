#!/bin/bash

cd app
rm -rf build 
mkdir build 
cd build
cmake ..
make -j $(nproc)
make install



