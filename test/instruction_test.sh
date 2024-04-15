#!/bin/bash
# Function to generate a unique number within a specified range
#
generate_unique_number() {
  local range=1000  # Accept range as an argumen
  local generated_numbers=()

  while true; do
    # Generate a random number within the range (inclusive)
    local random_num=$(($RANDOM))

    # Check if the number is already in the array
    if [[ ! "${generated_numbers[@]}" =~ " $random_num " ]]; then
      # Add the unique number to the array and print it
      generated_numbers+=("$random_num")
      echo "$random_num"
      return 0; # Exit the function after finding a unique number
    fi
  done
}

# Check for required argument (number of elements)
if [ $# -eq 0 ]; then
  echo "Error: Please specify the number of random numbers to generate."
  exit 1
fi

# Get the number of elements from the argument
num_elements=$1

# Validate if the argument is a positive integer
if [[ ! $num_elements =~ ^[0-9]+$ ]]; then
  echo "Error: Number of elements must be a positive integer."
  exit 1
fi

# Generate the specified number of unique random numbers
random_numbers=()
for ((i = 0; i < num_elements; i++)); do
  random_numbers+=($(generate_unique_number 40000))  # Pass range to function
done

echo "${random_numbers[@]}"
# Assuming sort_test and checker_linux are in your path or correct locations
echo "Numbers of instructions:"
./sort_test "${random_numbers[@]}" | wc -l

echo "Checker result:"
./sort_test "${random_numbers[@]}" | ./checker_linux "${random_numbers[@]}"
