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

    for i in range(2,int(ceil(sqrt(N)))):
        if i in primes:
            for j in range(i*i,N,i):
                primes.discard(j)

    return primes

def main():
    N = 300000
    primes = sieve(N)
    are = []
    for i in range(2,N):
        cnt = 0
        for p in primes:
            if i % p == 0:
                cnt += 1
        are.append((i,cnt))

    for i in range(N-3):
        if are[i][1] == 4 and  \
           are[i+1][1] == 4 and \
           are[i+2][1] == 4 and \
           are[i+3][1] == 4:
            print(are[i])

if __name__ == "__main__":
    main()
