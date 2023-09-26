#!/bin/bash

# variables
PROGRAM="./conversionofscalartypes"

TESTS=(
	"Char Test" "asdf." "Char!"
	"Int Test" "12345" "Int!"
	"Float Test" "23.01f" "Float!"
	"Double Test" "23.045" "Double!"
)

echo

for ((i=0; i<${#TESTS[@]}; i+=3)); do
	echo
	test_name="${TESTS[$i]}"
	test_value="${TESTS[$i+1]}"
	expected_output="${TESTS[$i+2]}"
	
	actual_output="$PROGRAM $test_value"
	
	if [ "$($actual_output)" == "$expected_output" ] ; then
		result=✅
	else
		result=❌
	fi

	echo $test_name
	echo $test_value $($actual_output) $expected_output $result
	echo
done

echo
