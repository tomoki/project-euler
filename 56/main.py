#!/usr/bin/env python
#coding:utf-8

from math import *
from string import *
from fractions import *
from itertools import *

def digitsum(n):
    return sum([int(c) for c in str(n)])

def main():
    print(max([digitsum(a ** b) for a in range(1,100) for b in range(1,100)]))

if __name__ == "__main__":
    main()
