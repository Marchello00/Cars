#!/bin/bash

brew install sfml
mkdir build
cd build
cmake ..
cmake --build .