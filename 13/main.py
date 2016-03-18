#!/usr/bin/env python
#coding:utf-8


def main():
    lis = []
    for i in range(100):
        x = int(input())
        lis.append(x)

    s = sum(lis)
    print(s)

if __name__ == "__main__":
    main()
