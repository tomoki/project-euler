#!/usr/bin/env python
#coding:utf-8

import math
import string
import fractions
import random

def main():
    tria = set()
    pent = set()
    hexa = set()

    N = 100000
    for n in range(1,N):
        tria.add(n*(n+1)/2)
        pent.add(n*(3*n-1)/2)
        hexa.add(n*(2*n-1))

    for t in tria:
        if t in pent and t in hexa:
            print(t)


if __name__ == "__main__":
    main()
