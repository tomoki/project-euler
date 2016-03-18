#!/usr/bin/env python
#coding:utf-8

from math import *
from string import *
from fractions import *
from itertools import *

def sieve(N):
    primes = set()
    for i in range(2,N):
        primes.add(i)

    for i in range(2,ceil(sqrt(N))):
        if i in primes:
            for j in range(i*i,N,i):
                primes.discard(j)

    return primes

def main():
    N = 1000000
    primes = sieve(N+1)
    lp = list(primes)
    r = 0
    ret = 0
    for i in range(0,len(lp)):
        print(i)
        for j in range(i+1,len(lp)):
            s = sum(lp[i:(j+1)])
            if(s > N):
                break
            if s in primes and (j-i) > r:
                ret = s
                r = (j-i)
                print((s,r))
    print(ret)


if __name__ == "__main__":
    main()
