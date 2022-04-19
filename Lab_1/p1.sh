#!/bin/bash
# 1901CS44
# Problem 1 code

if [ $# -eq 0 ]
then
    echo "Error: No argument provided."

elif [ $# -gt 1 ]
then
    echo "Error: Input should contain only one number."

else
    N=$(expr $1 + 0)
    K=0
    while [ $N -ne 0 ]
    do
        K=$(($K * 10 + $N % 10))
        N=$(($N / 10))
    done
    echo $K
fi