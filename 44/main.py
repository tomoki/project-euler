#!/usr/bin/env python
#coding:utf-8

import math
import string
import fractions
import random

def main():
    l = []
    ret = 10000000000
    for n in range(1,10000):
        l.append(round(n*(3*n-1)/2));
    #print(l)

    for i in range(len(l) // 10):
        print(i / (len(l)-1))
        for j in range(i+1,len(l) // 10):
            if (l[i]+l[j] in l) and (abs(l[i]-l[j]) in l):
                print(abs(l[i]-l[j]))
                ret = min(ret,abs(l[i]-l[j]))

    print(ret)
if __name__ == "__main__":
    main()
