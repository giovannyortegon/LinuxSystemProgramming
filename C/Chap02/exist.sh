#!/bin/bash

# check if the user supplied excatly one argument
if [ "$#" -ne 1 ]; then
	echo "You must supply exactly one argument."
	echo "Example: $0 /etc"
	exit 1 # Return with value 1
fi

# Check if the file/directory existS
test -e "$1" # Perform the actual test

if [ "$?" -eq 0 ]; then
    echo "File or directory exists."
elif [ "$?" -eq 1 ]; then
	echo "File or directory does not exist."
    exit 3      # Return with a special code so other
                # program can use the value to see of a
                # file doesn't exist
else
    echo "Unknown return value from test..."
    exit 1  # Unknown error occured, so exit with 1
fi
exit 0      # if the file or directory exists, we exit with
