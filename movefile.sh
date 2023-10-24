#!/bin/bash

for file in $(ls -d *[0-9]*.cpp);
do
    b=$file;
    [[ $b =~ ([0-9]+) ]];
    c=${BASH_REMATCH[1]};
    if [ -d "$c" ]; then
        mv $b "./Codeforce/$c"
    else
        mkdir "$c"
        mv $b "./Codeforce/$c"
    fi
done;
