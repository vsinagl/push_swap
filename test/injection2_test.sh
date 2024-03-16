#!/bin/bash

# Function to generate a random integer between -100 and 100
generate_random_number() {
  echo $((RANDOM % 20001 - 10000))
}

# Generate 100 random numbers and store them in an array
random_numbers=()
for ((i = 0; i < 5; i++)); do
  random_numbers+=($(generate_random_number))
done

# Call the sort binary with the generated numbers as parameters
~/Code/42/push_swap/sort_test "${random_numbers[@]}"
