#!/usr/bin/env python
#coding:utf-8

import math
import string
import fractions
import random

def main():
    s = set()
    for a in range(2,101):
        for b in range(2,101):
            s.add(a ** b)
    print(len(s))

if __name__ == "__main__":
    main()
