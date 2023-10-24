#!/bin/bash

for val in ${@:2} 
do 
    touch "$1$val.cpp"
    cat template.cpp >> $1$val.cpp
done;

# touch "$1A.cpp"
# touch "$1B.cpp"
# touch "$1C.cpp"
# touch "$1D.cpp"
# touch "$1E.cpp"
# touch "$1F.cpp"
