#!/bin/bash
# 1901CS44
# Problem 4 Code

echo -n "Enter directory_path: "
read DIR_PATH
echo -n "Enter filename_pattern: "
read FILE_PATTERN
echo -n "Enter the new_filename: "
read NEW_FILE_NAME

cd $DIR_PATH

FILE_NUM=1

# For each file
for FILE in *
do
    FILE_NAME="$(basename -- "$FILE")"
    # MATCHED is the number of matching characters
    MATCHED=0
    # Iterate for each matching character
    for ((i=0; i < ${#FILE_NAME} && MATCHED < ${#FILE_PATTERN}; i++))
    do
        if [ "${FILE_NAME:$i:1}" == ${FILE_PATTERN:$MATCHED:1} ]
        then
            MATCHED=$(($MATCHED + 1))
        fi
    done
    # If MATCHED is equak to len of File pattern then change name
    if [ $MATCHED -eq ${#FILE_PATTERN} ]
    then
        NEW_NAME=${NEW_FILE_NAME}_${FILE_NUM}.txt
        $(mv $FILE $NEW_NAME)
        ((FILE_NUM++))
    fi
done