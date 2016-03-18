#!/usr/bin/env python
#coding:utf-8

from math import *
from string import *
from fractions import *
from itertools import *

def reverse_add(n):
    return n + int(str(n)[::-1])

def is_palin(n):
    return str(n) == str(n)[::-1]

def is_lychrel(n,c):
    for i in range(c):
        n = reverse_add(n)
        if is_palin(n):
            return False
    return True

def main():
    cnt = sum([is_lychrel(i,100) for i in range(1,10000)]) 
    print(cnt)

if __name__ == "__main__":
    main()
