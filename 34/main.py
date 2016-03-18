#!/usr/bin/env python
#coding:utf-8

import math
import string
import fractions
import random

def fact(n):
    if n == 1 or n == 0:
        return 1
    else:
        return n * fact(n-1)

def main():
    ret = 0
    for i in range(3,1000000):
        s = str(i)
        h = 0 
        for c in s:
            h += fact(int(c))
        if i == h:
            ret += i
            print(i)
    print(ret)



if __name__ == "__main__":
    main()
