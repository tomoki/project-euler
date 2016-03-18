#!/usr/bin/env python
#coding:utf-8

from __future__ import division
from __future__ import print_function
from __future__ import unicode_literals

from math import *
from string import *
from fractions import *
from itertools import *
from sys import stdin

def main():
    ret = -1
    biggest = 0
    for (index,line) in enumerate(stdin):
        n,x = line.strip().split(",")
        n = int(n)
        x = int(x)
        nx = n ** x

        if nx > biggest:
            print(index)
            biggest = nx


if __name__ == "__main__":
    main()
