#!/bin/bash

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[0;33m'
NC='\033[0m' # No Color

# Change to the project root directory if script is run from scripts folder
SCRIPT_DIR=$(dirname "$0")
cd "$SCRIPT_DIR/.." || exit 1

echo -e "${YELLOW}=== Libft Tests Runner ===${NC}"
echo ""

# Compile all source files into a library first
echo -e "${YELLOW}Compiling libft...${NC}"
SRC_FILES=$(ls ft_*.c | grep -v "_test.c")
gcc -Wall -Wextra -Werror -c $SRC_FILES
ar rcs libft.a *.o
rm *.o

if [ $? -ne 0 ]; then
    echo -e "${RED}Failed to compile libft${NC}"
    exit 1
fi

echo -e "${GREEN}Libft compiled successfully${NC}"
echo ""

# Check if a specific test file is provided as an argument
if [ "$1" ]; then
    TEST_FILES="$1"
    if [ ! -f "$1" ]; then
        echo -e "${RED}Test file $1 does not exist.${NC}"
        exit 1
    fi
else
    TEST_FILES=$(ls ft_*_test.c 2>/dev/null)
fi

# Run each test
for test_file in $TEST_FILES; do
    # Extract the function name from the test file name
    func_name=$(echo $test_file | sed 's/_test\.c$//')

    echo -e "${YELLOW}Testing ${func_name}...${NC}"

    # Compile and link the test with our library
    gcc -Wall -Wextra -Werror ${test_file} -L. -lft -o temp_test

    if [ $? -eq 0 ]; then
        # Run the test and capture output
        test_output=$(./temp_test)
        echo "$test_output"

        # Check if the test had any fails
        if echo "$test_output" | grep -q "\[FAIL\]"; then
            echo -e "${RED}${func_name} tests FAILED${NC}"
        else
            echo -e "${GREEN}${func_name} tests PASSED${NC}"
        fi
    else
        echo -e "${RED}Compilation FAILED for ${func_name}${NC}"
    fi

    # Clean up
    if [ -f "temp_test" ]; then
        rm temp_test
    fi

    echo ""
done

# Clean up library
rm libft.a

echo -e "${YELLOW}All tests completed.${NC}"
