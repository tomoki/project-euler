#!/usr/bin/env python
#coding:utf-8

import math
import string
import fractions
import random

def recurring(nu,de):
    if nu % de == 0:
        return str(nu / de)
    else:
        # interger section
        ret = str(nu // de) + "."
        nu %= de
        reminder_history = []
        while True:
            reminder_history.append(nu)
            nu *= 10
            ret += str(nu // de)
            nu %= de
            if nu == 0:
                break
            if nu in reminder_history:
                h = reminder_history.index(nu)
                ret = ret[:h+2] + "(" + ret[h+2:] + ")"
                break

        return ret

def main():
    l = 0
    ret = ""
    o = 0
    for d in range(1,1000):
        s = recurring(1,d)
        if '(' in s:
            k = s.index(')') - s.index('(') + 1
            if k > l:
                o = d
                print(ret)
                l = k
                ret = s

    print((o,ret))

if __name__ == "__main__":
    main()
