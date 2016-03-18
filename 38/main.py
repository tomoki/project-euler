#!/usr/bin/env python
#coding:utf-8

import math
import string
import fractions
import random
import itertools

def main():
    ret = ""
    for i in range(1,1000000):
        s = ""
        for j in range(1,100):
            s += str(i*j)
            if len(s) >= 9 and j > 1:
                break
        if len(s) == 9:
            se = set()
            for c in s:
                se.add(c)
            if len(se) == 9 and not '0' in se:
                print(s)

if __name__ == "__main__":
    main()
