#!/usr/bin/env python
#coding:utf-8

def score(name):
    ret = 0
    for c in name:
        ret += ord(c) - ord('A') + 1
    return ret

def main():
    ret = 0
    names = eval("["+input() +"]");
    names.sort()
    for (index,name) in enumerate(names):
        ret += score(name) * (index+1)
        print((index+1,name,score(name)))
    print(ret)

if __name__ == "__main__":
    main()
