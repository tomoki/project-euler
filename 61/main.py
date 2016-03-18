#!/usr/bin/env python
#coding:utf-8

from __future__ import division
from __future__ import print_function
from __future__ import unicode_literals

from math import *
from string import *
from fractions import *
from itertools import *

def p3(n):
    return n*(n+1)//2

def p4(n):
    return n ** 2

def p5(n):
    return n*(3*n-1)//2

def p6(n):
    return n*(2*n-1)

def p7(n):
    return n*(5*n-3)//2

def p8(n):
    return n*(3*n-2)

# 4-digit only
def cyclic(left,right):
    return str(left)[2:] == str(right)[:2]

def solve(have,used,lis):
    if used == (1 << 6)-1:
        if cyclic(have[-1],have[0]):
            print(have,sum(have))
    else:
        for i in range(6):
            if used & (1 << i) == 0:
                for j in lis[i]:
                    if len(have) == 0 or cyclic(have[-1],j):
                        have.append(j)
                        solve(have,used | (1 << i),lis)
                        have.pop()

def main():
    funcs = []
    funcs.append(p3)
    funcs.append(p4)
    funcs.append(p5)
    funcs.append(p6)
    funcs.append(p7)
    funcs.append(p8)

    lis = []
    for f in funcs:
        fli = []
        for i in range(1,1000000000):
            val = f(i)
            if val >= 10000:
                break
            elif val >= 1000:
                fli.append(val)
        lis.append(fli)

    solve([],0,lis)

if __name__ == "__main__":
    main()
