#!/usr/bin/env bash

set -e

flags="-Iinclude/ -fopenmp -Wall -Wextra -Werror \
     -Wcast-align -Wshadow  -Wpointer-arith \
     -Wcast-qual -Wno-missing-braces  -Wunreachable-code \
     -Wfloat-equal  -Wno-missing-field-initializers"

echo "##########################################################################"
echo "#                         BUILDING aCAT                                  #"
echo "##########################################################################"
find ./src -name "*.c" -print0 | while read -d $'\0' file
do
    output=$(echo $file | sed 's|^./src/|./build/|')
    output="${output%.c}.o"
    directory=$(dirname "$output")
    mkdir -p $directory
    run="mpicc -c $file -o $output $flags"
    echo $run
    eval $run
done

echo "##########################################################################"
echo "#                        BUILDING EXAMPLES                               #"
echo "##########################################################################"
objects=$(find ./build -name "*.o" -print0 | xargs -0)
examples=$(find ./examples -name "*.c" -print0 | xargs -0)
for arg in $examples; do
    mkdir -p ./bin/examples
    output=$(basename "$arg")
    output="./bin/examples/${output%.c}"
    run="mpicc $arg -o $output $flags $objects"
    echo $run
    eval $run
done

echo "##########################################################################"
echo "#                         RUNNING EXAMPLES                               #"
echo "##########################################################################"
tests=$(find ./bin/examples -type f -name "*" -print0 | xargs -0)
for arg in $tests; do
    run="mpirun -np 1 ./$arg"
    echo $run
    eval $run
    run="mpirun -np 4 ./$arg"
    echo $run
    eval $run
done

for arg in "$@"; do
    mkdir -p ./bin
    output=$(basename "$arg")
    output="./bin/${output%.c}"
    run="mpicc $arg -o $output $flags $objects"
    echo $run
    eval $run
done
