#!/usr/bin/env python
#coding:utf-8

import math
import string
import fractions
import random
import itertools

def li(lis):
    ret = 0
    for l in lis:
        ret *= 10
        ret += l
    return ret


def main():
    ret = 0
    lis = list(range(10))
    for l in itertools.permutations(lis):
        if li(l[1:4]) % 2 == 0 and li(l[2:5]) % 3 == 0 and li(l[3:6]) % 5 == 0 and li(l[4:7]) % 7 == 0 and li(l[5:8]) % 11 == 0 and li(l[6:9]) % 13 == 0 and li(l[7:10]) % 17 == 0 :
            ret += li(l)
    print(ret)
if __name__ == "__main__":
    main()
