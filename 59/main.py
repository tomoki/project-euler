#!/usr/bin/env python
#coding:utf-8

from __future__ import division
from __future__ import print_function
from __future__ import unicode_literals

from math import *
from string import *
from fractions import *
from itertools import *

try:
    input = raw_input
except:
    pass

def main():
    cs = eval("[" + input() +"]")

    for i in ascii_lowercase:
        for j in ascii_lowercase:
            for k in ascii_lowercase:
                key = i + j + k
                dec = []
                for (l,c) in enumerate(cs):
                    dec.append(c ^ ord(key[l % 3]))

                dec_string = "".join([chr(a) for a in dec])
                commons = ["the","be","to","of",
                        "and","a","in","that"]

                ok = True
                for common in commons:
                    ok = ok and common in dec_string
                if ok:
                    print(key)
                    print(sum(dec))

if __name__ == "__main__":
    main()
