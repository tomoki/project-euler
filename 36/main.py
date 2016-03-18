#!/usr/bin/env python
#coding:utf-8

import math
import string
import fractions
import random

def is_palin(s):
    return s == s[::-1]

def binary_format(n):
    return bin(n)[2:]

def is_ok(n):
    s = str(n)
    b = binary_format(n)
    return is_palin(s) and is_palin(b)

def main():
    ret = 0
    for i in range(1000000):
        if is_ok(i):
            ret += i
    print(ret)

if __name__ == "__main__":
    main()
