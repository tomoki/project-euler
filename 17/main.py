#!/usr/bin/env python
#coding:utf-8

import math
import string
import fractions
import random

def wordfy(n):
    sand = "and"
    dic = {
            1:"one",2:"two",3:"three",4:"four",5:"five",6:"six",7:"seven",
            8:"eight",9:"nine",10:"ten",11:"eleven",12:"twelve",13:"thirteen",
            14:"fourteen",15:"fifteen",16:"sixteen",17:"seventeen",18:"eighteen",
            19:"nineteen",20:"twenty",30:"thirty",40:"forty",50:"fifty",60:"sixty",
            70:"seventy",80:"eighty",90:"ninety",100:"hundred",1000:"thousand"
            }
    if n in dic:
        if n == 100:
            return dic[1] + dic[100]
        elif n == 1000:
            return dic[1] + dic[1000]
        else:
            return dic[n]
    else:
        sn = str(n)
        if len(sn) >= 3:
            ret = dic[int(sn[0])] + dic[100] 
            if int(sn[1:])in dic:
                    ret += sand + dic[int(sn[1:])]
            elif int(sn[1]) == 0:
                if int(sn[2]) == 0:
                    pass
                else:
                    ret += sand + dic[int(sn[2])]
            else:
                ret += sand + dic[int(sn[1])*10] + dic[int(sn[2])]
            return ret
        else:
            return dic[int(sn[0])*10] + dic[int(sn[1])]

def main():
    ret = 0
    for i in range(1,1001):
        w = wordfy(i)
        ret += len(w)
        print((i,wordfy(i),len(w)))
    print(ret)

if __name__ == "__main__":
    main()
