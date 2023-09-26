#!/bin/bash


# variables
PROGRAM="./conversionofscalartypes"

OUTPUT=$($PROGRAM asdfg)

EXPECTED={"Char!", "Int!"}

echo
for TEST_CASE in $EXPECTED; do
	if [ "$OUTPUT" == "$TEST_CASE" ]; then
		echo "$OUTPUT ✅"
	else
		echo "$OUTPUT ❌"
	fi
done
echo
