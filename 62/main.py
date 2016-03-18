#!/usr/bin/env python
#coding:utf-8

from __future__ import division
from __future__ import print_function
from __future__ import unicode_literals

from math import *
from string import *
from fractions import *
from itertools import *

def main():
    sorted_cube = {}
    for i in range(1,10000):
        p = i ** 3
        s = "".join(sorted(str(p)))
        if s in sorted_cube:
            sorted_cube[s].append(p)
            if len(sorted_cube[s]) >= 5:
                print(sorted_cube[s])
                return
        else:
            sorted_cube[s] = [p]
if __name__ == "__main__":
    main()
