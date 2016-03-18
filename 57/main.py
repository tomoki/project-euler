#!/usr/bin/env python
#coding:utf-8

from math import *
from string import *
from fractions import *
from itertools import *

ma = {}
def deno(n):
    if n in ma:
        return ma[n]
    ret = 0
    if n == 0:
        ret = 2
    else:
        ret = (2 + Fraction(1,deno(n-1)))
    ma[n] = ret
    return ret

def ite(n):
    return 1 + Fraction(1,deno(n))

def main():
    cnt = 0
    for i in range(1000):
        a = ite(i)
        if len(str(a.numerator)) > len(str(a.denominator)):
            print(a)
            cnt += 1
    print(cnt)

if __name__ == "__main__":
    main()
