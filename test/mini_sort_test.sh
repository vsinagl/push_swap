#!/bin/bash

# Generate all permutations of given digits
generate_permutations() {
    local prefix=$1
    local remaining=$2

    if [ ${#remaining} -eq 0 ]; then
        echo $prefix
    else
        for ((i=0; i<${#remaining}; i++)); do
            local next_char="${remaining:i:1}"
            local rest="${remaining:0:i}${remaining:i+1}"
            generate_permutations "$prefix${next_char}" "$rest"
        done
    fi
}

# Generate all permutations of 123
digits="123"
permutations=$(generate_permutations "" "$digits")
echo permutations

# Run the test program with each permutation
for perm in $permutations; do
    echo $perm
done
