#!/bin/bash

for i in {1..10}
do
#linux
    # max_range=$(shuf -i 0-2147483647 -n 1)
    # num_elements=$(shuf -i 1-200 -n 1)
    # args=$(shuf -i 1-$max_range -n $num_elements | tr "\n" " ")

#macOS
    max_range=$(jot -r 1 1 2147483647)
    num_elements=10
    args=$(jot -r $num_elements 1 $max_range | tr "\n" " ")

    ./PmergeMe $args
done