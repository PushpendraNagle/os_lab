# !/bin/bash
# 1901CS44
# Lab 2
# Q3

calc_xor () {
    # Copy to temporary variables
    temp1=$1
    temp2=$2

    # Stores final result
    res=0
    # Power of 2
    pwr_2=1
    # While any one is more than 0
    while [[ temp1 -gt 0 ]] || [[ temp2 -gt 0 ]]
    do
        # Calculate Least Significant Bit
        temp1_bit=$(($temp1 % 2))
        temp1=$(($temp1 / 2))
        temp2_bit=$(($temp2 % 2))
        temp2=$(($temp2 / 2))

        # Take XOR
        cur_xor=$(($temp1_bit * !$temp2_bit + !$temp1_bit * $temp2_bit))
        
        # Add to final result
        res=$(($res + $cur_xor * $pwr_2))
        # Increase power of 2
        pwr_2=$(($pwr_2 * 2))
    done

    echo "XOR of $1 and $2 = $res"
}

# If two numbers are provided
if [[ $# -eq 2 ]]
then
    # Calculate XOR
    calc_xor $1 $2
else
    # Show error
    echo "Error: Enter 2 integers only."
fi