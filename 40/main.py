#!/usr/bin/env python
#coding:utf-8

import math
import string
import fractions
import random

def main():
    i = 1
    s = ""
    while len(s) < 1000000:
        s += str(i)
        i += 1
    ret = 1
    for i in range(7):
        ret *= int(s[10**i-1])
    print(ret)


if __name__ == "__main__":
    main()
