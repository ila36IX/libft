#!/bin/bash
func=$1
if [[ -z $func ]]; then
	echo "Please provide at least one function to test"
	exit 1
fi
gcc "ft_$func.c" "tests/test_ft_$func.c" -o exectest && ./exectest
