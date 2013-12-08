#!/bin/bash

# Convert from STL format to Cpp code
set -x
grep 'vertex' | sed -r 's/([0-9]) /\1,/g' | sed -r 's/vertex/addVertex\(vertices, EXf, r, g, b, a, pos + sf::Vector3f(/' | sed -r 's/$/\)\);/' | xclip -selection c

