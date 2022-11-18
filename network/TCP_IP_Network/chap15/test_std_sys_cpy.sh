#!/bin/bash

FILE="news.txt"

#1. create news.txt file
echo "begin to prepare '$FILE'."

if [[ -r $FILE ]]; then
	echo "$FILE exists."
else
	for _ in {0..10000}; do
		cat syscpy.c >>$FILE
	done
	echo "$FILE is ready."
fi

echo -n "sizeof $FILE is: "
du -h $FILE

echo "use syscpy:"
time ./syscpy.out

sleep 1

echo "use stdcpy:"
time ./stdcpy.out

: '
begin to prepare 'news.txt'.
news.txt exists.
sizeof news.txt is: 4.0M    news.txt
use syscpy:

real    0m3.603s
user    0m0.400s
sys 0m3.193s
use stdcpy:

real    0m0.176s
user    0m0.162s
sys 0m0.012s 
'
