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
    for f in range(1000,10000):
        for u in range(1,5001):
            lis = [0 for i in range(3)]
            for i in range(3):
                lis[i] = f + u * i

            if lis[2] > 9999:
                break

            slis = [str(l) for l in lis]

            if lis[0] in primes and lis[1] in primes and lis[2] in primes and \
               tuple(slis[1]) in permutations(slis[0]) and \
               tuple(slis[2]) in permutations(slis[0]) :

                print(lis)
                print(sum(lis))


if __name__ == "__main__":
    main()
