#!/usr/bin/env python
#coding:utf-8

from math import *
from string import *
from fractions import *
from itertools import *

def main():
    x = 0
    for i in range(1,1001):
        x += i ** i
    print(str(x)[-10:])



if __name__ == "__main__":
    main()
