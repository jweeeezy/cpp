#!/bin/bash

# variables
PROGRAM="./conversionofscalartypes"

TESTS=(
	"Char Test" "CHAR!" "a" "f" "."
	"Int Test" "INTEGER!" "12345" "-12" "917831273812378"
	"Float Test" "FLOAT!" "23.01f" "123f"
	"Double Test" "DOUBLE!" "23.045" "1.00"
)


echo
i=0
while [ $i -lt ${#TESTS[@]} ]; do
	test_name="${TESTS[$i]}"
	expected_output="${TESTS[$i+1]}"
	i=$((i+2))

	echo "$test_name:"

	while [[ $i -lt ${#TESTS[@]} && ! "${TESTS[$i]}" =~ " Test" ]]; do
		test_value="${TESTS[$i]}"
		
		actual_output=$($PROGRAM $test_value)
		if [ "$actual_output" == "$expected_output" ] ; then
			result=✅
		else
			result=❌
		fi

		echo -n "\"$test_value\" $result " "[$actual_output / $expected_output]"
		echo
		i=$((i+1))
	done
	echo
done
