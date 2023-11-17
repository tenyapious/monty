#!/bin/bash

# Define colors
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# List of all test scripts
test_scripts=("0-no_argument.sh" "1-file_doesnt_exist.sh" "2-empty_file.sh" "3-invalid_instructions.sh" "4-spaces_1.sh" "5-spaces_2.sh" "7-checker.sh" "1-checker.sh" "2-checker.sh" "3-checker.sh" "4-checker.sh" "5-checker.sh" "6-checker.sh")

# Loop over all test scripts
for script in ${test_scripts[@]}; do
    echo "Running $script..."
    bash $script
    if [ $? -eq 0 ]; then
        echo -e "${GREEN}Test $script passed.${NC}"
    else
        echo -e "${RED}Test $script failed.${NC}"
    fi
done