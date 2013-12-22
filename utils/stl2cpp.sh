#!/bin/bash

# Convert from STL format to Cpp code
set -x

./exe_stl2cpp/stl2cpp "$1" | xclip -selection c

