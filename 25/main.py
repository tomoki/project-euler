#!/usr/bin/env python
#coding:utf-8

def main():
    a = 1
    b = 1
    cnt = 2
    while len(str(b)) < 1000:
        b,a = a + b,b
        print(b)
        cnt += 1
    print(cnt)

if __name__ == "__main__":
    main()
