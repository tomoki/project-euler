#!/usr/bin/env python
#coding:utf-8

from math import *
from string import *
from fractions import *
from itertools import *

def tol(n):
    return sorted(str(n))

def main():
    for n in range(1,100000000):
        a = tol(n)
        ok = True
        for j in range(2,7):
            ok = ok and tol(j*n) == a
        if ok:
            print(n)


if __name__ == "__main__":
    main()
