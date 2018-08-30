#!/bin/bash

BIN="./bin"
TEST="./test"

for f in $TEST/*.in; do
	f=${f%*.in}
	timeout 10s $BIN/freq < ${f}.in > ${f}.tmp
	if [ $? -eq 124 ]; then
		echo "${f}.in timed out <---"
		continue
	fi
	DIFF=$(diff ${f}.ans ${f}.tmp)
	if [ "$DIFF" != "" ]; then
		echo "${f}.in failed <---"
	else
		echo "${f}.in passed"
	fi
	rm ${f}.tmp
done

