# !/bin/bash
# 1901CS44
# Lab 2
# Q2

# Recursive function for factorial
function fact() { 
    # Base case
    if (( $1 < 2 ))
    then
        echo 1
        return
    else	
        # Fact(n) = n * Fact(n-1)
        echo $(( $1 * $(fact $(( $1 - 1 )))))
    fi
}

# Recursive function for sum of prime less than or equal to a given number
function PrimeNoLessThan() {
    # Base case
	if (($1 < 2))
	then
		echo 0
        return
	else
		for((i=2;i<$1;i++))
		do
            # If divisible it is not prime
			if [[ $(($1 % $i)) -eq 0 ]]
			then
                # Find another prime by subtracting 1
				echo $(PrimeNoLessThan $(( $1 - 1)) )
				return
			fi
		done
        # Number is prime so add it
		echo $(( $1 + $(PrimeNoLessThan $(( $1 - 1))) ))
	fi
}

# If single number entered
if [ $# -eq 1 ]
then
    # Output the result
    echo "Result = $(( $(PrimeNoLessThan $1) * $(fact $1) ))"
else
    # Show error
    echo "Error: Multiple numbers entered."
fi
