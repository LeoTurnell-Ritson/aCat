#!/usr/bin/env bash

set -e

find ./src -name "*.c" -print0 | while read -d $'\0' file
do
    output=$(echo $file | sed 's|^./src/|./build/|')
    output="${output%.c}.o"
    directory=$(dirname "$output")
    mkdir -p $directory
    run="mpicc -c $file -o $output -Iinclude/ -fopenmp -Wall -Wextra -Werror  -Wcast-align -Wshadow  -Wpointer-arith -Wcast-qual -Wno-missing-braces  -Wunreachable-code -Wfloat-equal  -Wno-missing-field-initializers"
    echo $run
    eval $run
done

objects=$(find ./build -name "*.o" -print0 | xargs -0)

for arg in "$@"; do
    output=$(basename "$arg")
    output="./bin/${output%.c}"
    run="mpicc $arg -o $output -Iinclude/ -fopenmp -Wall -Wextra -Werror  -Wcast-align -Wshadow  -Wpointer-arith -Wcast-qual -Wno-missing-braces  -Wunreachable-code -Wfloat-equal  -Wno-missing-field-initializers $objects"
    echo $run
    eval $run
done
