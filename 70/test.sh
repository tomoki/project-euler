#!/bin/sh

# put test.sh ,input files and output files in the same folder.
# $ ls
# test.sh main.cpp 1.in 1.out 2.in 2.out

INPUTS=`find . -type f -name "*.in" | sort`
PROG=$1

if [ $# -eq 0  ]
then
    echo "Pass program as first argument."
    echo "ex: ./test.sh ./a.out"
    exit 1
fi

cnt=0
suc=0
for input in $INPUTS
do
    cnt=`expr $cnt + 1`
    body=${input%.*}
    output=$body.out
    echo "$input - $output"
    if [ -e $output ]
    then
        tmp=`mktemp`
        $PROG < $input > $tmp
        d=`diff $output $tmp -Z`
        if [ ${#d} -eq 0 ]
        then
            echo -e "\033[0;32mCorrect\033[0;39m"
            suc=`expr $suc + 1`
        else
            echo -e "\033[0;31mFailed\033[0;39m"
            echo "Expected:"
            cat $output
            echo "Output:"
            cat $tmp
        fi
        rm $tmp
    else
        echo -e "\033[0;31mFailed <- $output not found\033[0;39m"
    fi
done

if [ $cnt -eq $suc ]
then
    echo -e "\033[0;32mAll test Passed!!\033[0;39m"
else
    echo -e "\033[0;31mSome test failed.("`expr $cnt - $suc`"/$cnt)\033[0;39m"
fi
