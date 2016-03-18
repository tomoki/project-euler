#!/usr/bin/env python
#coding:utf-8

from math import *
from string import *
from fractions import *
from itertools import *

def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n-1)

def ncr(n,r):
    return factorial(n) // (factorial(r) * factorial(n-r))

def main():
    cnt = 0
    for n in range(1,101):
        for c in range(1,n+1):
            if ncr(n,c) > 1000000:
                cnt += 1
    print(cnt)

if __name__ == "__main__":
    main()
