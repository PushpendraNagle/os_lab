#!/bin/bash
# 1901CS44
# Lab 2
# Q1

# Store array
arr=(${@:2:$(($1))})
# Store element to search
k=${!#}
# Set is_found as -1, it will hold index of searched element
is_found=-1
i=0
# Check in array
for j in "${arr[@]}"
do
    if [ $j -eq $k ]
    then 
        # If found, set is_found as index of element
        is_found=$i
    fi
    ((i++))
done

if [ $is_found -eq -1 ]
then    
    echo "Error: Element not found."
else
    echo "Element found at $is_found index."
fi