#!/bin/bash
# 1901CS44
# Problem 2 code

echo -n "Input A: "
read A
echo -n "Input B: "
read B

# If first number is greater than second
# Show error
if [ $A -gt $B ]
then
    echo "Error: First number must be smaller than second."

else 
    while [ $A -le $B ]
    do
        echo -n "$A "
        A=$(($A + 1)) 
    done
    echo ""
fi