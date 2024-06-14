#!/bin/bash

flags=(-Wall -Wextra -Werror)
#files=("mergesort_t.c" "../../src/utils3.c" "../../src/list.c" "../../src/ops1.c" "../../src/sort2.c" "../../src/utils1.c" "../../src/utils2.c" "../../src/utils3.c" "../../src/middleway.c" )
files=("mergesort_t.c" "../../src/utils3.c")
output="mergesort_test"

cc "${flags[@]}" "${files[@]}" -o "$output"


if [ $? -eq 0 ]; then
    echo "Compilation successful. Executable '$output' created."
else
    echo "Compilation failed."
fi
