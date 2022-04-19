#!/bin/bash
# 1901CS44
# Problem 3 code

# If number of arguments less than 2
# Show Error message
if [ $# -ne 2 ] 
then
    echo "Error: Invalid number of arguments."
else
    FILE_NAME=$1
    NUM_OF_LINES=$2
    CNT=0
    # Count number of lines
    while read -r line || [ -n "$line" ]
    do
        CNT=$(($CNT + 1))
    done  < "$FILE_NAME"
    
    echo "Number of lines in file: $CNT"

    if [ $CNT -lt $NUM_OF_LINES ]
    then
        echo "Less number of lines, deleting file."
        rm -f $FILE_NAME
    fi
fi