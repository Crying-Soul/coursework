#!/bin/bash

make
echo "----------------------"
./coursework < tests/test-cyrillic
echo "----------------------"
make clean

# if [ "$#" -eq 1 ]; then
#     test_file="$1"
# else

#     echo "Using default test's file..."
#     test_file="default"
# fi

# run_tests() {
#     test_number=0
#     current_test=""
    
#     while IFS= read -r line; do
#         if [[ $line == "#Test"* ]]; then
#             if [ -n "$current_test" ]; then
#                 test_number=$((test_number+1))
#                 echo -e "\033[31mRunning test $test_number\033[0m"
#                 echo -e "$current_test" | ./coursework
#                 sleep 1.5
#             fi
#             current_test=""
#         else
#             current_test="$current_test\n$line"
#         fi
#     done < "tests/$1"
    
#     if [ -n "$current_test" ]; then
#         test_number=$((test_number+1))
#         echo -e "\033[31mRunning test $test_number\033[0m"
#         echo -e "$current_test" | ./coursework
#         sleep 1.5
#     fi
# }

# if make; then
#     run_tests "$test_file"
#     make clean
#     echo -e "\033[1;92m------------\033[0m"
#     echo -e "\033[1;92mTests ended!\033[0m"
#     echo -e "\033[1;92m------------\033[0m"
# else
#     echo "Compilation error..."
# fi
