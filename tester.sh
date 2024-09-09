#!/bin/bash

# Loop through different numbers of inputs
printf "Input\tAvg\tMin\tMax of instructions\n"
rm -f performance_results.csv
for n in {10..600..10}; do
    # Runing executable multiple times and recording the outputs
    instructions=()
    for ((i = 0; i < 15; i++)); do   
        output=$(./push_swap $(shuf -i 1-$n -n $n) | wc -l)
        instructions+=($output)
    done

    # Calculating some basics statistics
    avg=$(echo "${instructions[@]}" | awk '{s=0; for(i=1;i<=NF;i++)s+=$i; print s/NF}')
    min=$(echo "${instructions[@]}" | tr ' ' '\n' | sort -n | head -n1)
    max=$(echo "${instructions[@]}" | tr ' ' '\n' | sort -n | tail -n1)

    # Result output
	printf "$n\t$avg\t$min\t$max\n"
    echo "$n,$avg,$min,$max" >> performance_results.csv
done

# running analysis.py for creating graphical view of analysis
python3 analysis.py

# Tests on specific imput 
run_tests() {
    local num=$1
    local total=0
    local min=999999999
    local max=0
    local times=100

    # Running multiple tests
    for ((i = 0; i < $times; i++)); do
        output=$(./push_swap $(shuf -i 1-$num -n $num) | wc -l)
        total=$((total + output))
        if [ $output -lt $min ]; then
            min=$output
        fi
        if [ $output -gt $max ]; then
            max=$output
        fi
    done

    # Calculating average
    average=$((total / $times))

    # Printing results
    echo ""
    echo "Number of Inputs: $num"
    echo "Number of tests: $times"
    echo "Average Instructions: $average"
    echo "Minimum Instructions: $min"
    echo "Maximum Instructions: $max"
}

run_tests 100
run_tests 500
