#!/usr/bin/env python
#coding:utf-8

from __future__ import division
from __future__ import print_function
from __future__ import unicode_literals

from math import *
from string import *
from fractions import *
from itertools import *

def is_end_89(n):
    nex = sum([int(c)*int(c) for c in str(n)])
    if nex == 89:
        return True
    elif nex == 1:
        return False
    else:
        return is_end_89(nex)

def main():
    ret = 0
    for i in range(1,10000000):
        if is_end_89(i):
            ret += 1
    print(ret)

if __name__ == "__main__":
    main()
