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
    s = set()
    for i in range(1,100):
        for j in range(1,100):
            if len(str(i ** j)) == j:
                s.add(i ** j)
    print(s)
    print(len(s))


if __name__ == "__main__":
    main()
