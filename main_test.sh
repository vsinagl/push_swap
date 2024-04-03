#!/bin/bash

# Function to generate a random integer between -100 and 100
generate_random_number() {
  echo $((RANDOM % 20001 - 10000))
}

if [ "$#" -eq 0 ]; then
  echo "error: no parametr. Select how many numbers should be generated\n"
else
  nums=$1
fi

# Generate 100 random numbers and store them in an array
random_numbers=()
for ((i = 0; i < $nums; i++)); do
  random_numbers+=($(generate_random_number))
done

# Call the sort binary with the generated numbers as parameters
echo "input numbers: ${random_numbers[@]}"
echo "numbers of instructions: "
~/Code/42/push_swap/sort_test "${random_numbers[@]}" | wc -l
echo "checker result: "
~/Code/42/push_swap/sort_test "${random_numbers[@]}" | ./checker_linux ${random_numbers[@]}
