#!/usr/bin/env python
#coding:utf-8

import math
import string
import fractions
import random

def main():
    ret = fractions.Fraction(1,1)
    for d in range(10,100):
        for n in range(10,d):
            f = fractions.Fraction(n,d)

            sd = str(d)
            sn = str(n)

            if d % 10 == 0 and n % 10 == 0:
                break
            for i in range(2):
                for j in range(2):
                    if sd[i] == sn[j]:
                        aa = int(sd[i != 1])
                        bb = int(sn[j != 1])
                        if(aa == 0):
                            continue
                        if f == fractions.Fraction(bb,aa):
                            ret *= f
                            print(sd,sn)
                            print(f)

    print(ret)
if __name__ == "__main__":
    main()
