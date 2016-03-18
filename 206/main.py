#!/usr/bin/env python
#coding:utf-8

from __future__ import division
from __future__ import print_function
from __future__ import unicode_literals

from math import *
from string import *
from fractions import *
from itertools import *

import re

def main():
    #               1000000000000000000
    #               0 x 18
    r = re.compile("1.2.3.4.5.6.7.8.9.0")
    for i in range(10**9,10**10):
        s = str(i*i)
        if r.match(s):
            print(i)


if __name__ == "__main__":
    main()
