#!/usr/bin/env python
#coding:utf-8

import math
import string
import fractions
import random

def main():
    ret = 0
    names = eval("[" + input() + "]")
    tri = [0]
    for i in range(1000):
        tri.append(tri[-1]+i)

    for name in names:
        t = 0
        for c in name:
            t += ord(c) - ord('A') + 1
        if t in tri:
            ret += 1
    print(ret)



if __name__ == "__main__":
    main()
