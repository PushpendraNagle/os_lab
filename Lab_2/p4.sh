# !/bin/bash
# 1901CS44
# Lab 2
# Q4

# Check if password entered
if [ $# -ne 1 ]
then    
    echo "Error: No password entered."
	exit 1
fi

# Declare character arrays
arr="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
num="0123456789"
brr="/()<>?"
# Take input password
password=$1
len=${#password}
echo "Password Entered: $1"
echo "Length of Password: $len"

# Check length of password
if [ $len -lt 7 ]
then
    echo "<Invalid password>"
    echo "Must be atleast 7 characters long."
    exit 1
fi


function check_password() {
    flag1=0 # check alphabets
    flag2=0 # check numbers
    flag3=0 # check special characters
	for ((i = 0; i < $len; ++i))
    do
        # Match alphabets
		for ((j = 0; j < ${#arr}; ++j))
        do
			if [ ${password:i:1} == ${arr:j:1} ]; 
			then
				flag1=1
			fi
		done
        # Match numbers
        for ((j = 0; j < ${#num}; ++j))
        do
			if [ ${password:i:1} == ${num:j:1} ]; 
			then
				flag2=1
			fi
		done
        # Match special characters
        for ((j = 0; j < ${#brr}; ++j))
        do
			if [ ${password:i:1} == ${brr:j:1} ]; 
			then
				flag3=1
			fi
		done
	done

    # If anyone is not present show invalid
    if [ $flag1 -eq 1 ] && [ $flag2 -eq 1 ]	&& [ $flag3 -eq 1 ]
    then    
        echo "<Strong and valid password>"
    else
        echo "<Weak and invalid password>"
    fi
}

# Call check_password function
check_password

