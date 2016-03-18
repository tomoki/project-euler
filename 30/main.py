#!/usr/bin/env python
#coding:utf-8

import math
import string
import fractions
import random

def main():
    ret = 0
    for n in range(2,1000000):
        s = str(n)
        o = 0
        for si in s:
            o += int(si) ** 5
        if n == o:
            ret += n

    print(ret)

if __name__ == "__main__":
    main()
