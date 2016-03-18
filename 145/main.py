#!/usr/bin/env python
#coding:utf-8

def is_ok(n):
    if n % 10 == 0:
        return False
    for c in str(n + int("".join(reversed(str(n))))):
        if int(c) % 2 == 0:
            return False
    return True

def main():
    N = 1000000000
    ret = 0
    for i in range(1,N):
        if i % 100000 == 0:
            print(i / N * 100,"%")
        if is_ok(i):
            ret += 1
    print(ret)

if __name__ == "__main__":
    main()
