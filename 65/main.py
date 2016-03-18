#!/usr/bin/env python
#coding:utf-8

from __future__ import division
from __future__ import print_function
from __future__ import unicode_literals

from math import *
from string import *
from fractions import *
from itertools import *

def nk(n):
    if n % 3 == 1:
        return 2 * (n // 3 + 1)
    else:
        return 1

def np(n):
    def rec(k):
        if k == n-1:
            return nk(k)
        else:
            return nk(k) + Fraction(1,rec(k+1))
            pass

    if n == 0:
        return 2
    else:
        return 2 + Fraction(1,rec(0))

def solve(n):
    f = np(n)
    return sum([int(c) for c in str(f.numerator)])

def main():
    print(solve(99))


if __name__ == "__main__":
    main()
