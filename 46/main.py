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
    primes = sieve(10000)
    s = set()
    for i in range(1,100):
        for j in primes:
            s.add(j+2*i**2)
    for i in range(1,10000,2):
        if i not in s and i not in primes:
            print(i)



if __name__ == "__main__":
    main()
