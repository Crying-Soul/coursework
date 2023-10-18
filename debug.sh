#!/bin/bash


if gcc -Wall -Wextra -pedantic -o lab-3.out main.c; then
    test_number=0
    current_test=""
    
    while IFS= read -r line; do
        if [[ $line == "#Test"* ]]; then
            if [ -n "$current_test" ]; then
                test_number=$((test_number+1))
                echo -e "\033[31mRunning test $test_number\033[0m"
                echo -e "$current_test" | ./lab-3.out
                sleep 1.5
            fi
            current_test=""
        else
            current_test="$current_test\n$line"
        fi
    done < tests
    
    if [ -n "$current_test" ]; then
        test_number=$((test_number+1))
        echo -e "\033[31mRunning test $test_number\033[0m"
        echo -e "$current_test" | ./lab-3.out
    fi
else
    echo "Ошибка компиляции программы."
fi

rm -f lab-3.out

