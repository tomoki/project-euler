#!/usr/bin/env python
#coding:utf-8

import calendar

# include to_year and to_month
def count(from_year,from_month,to_year,to_month):
    ret = 0
    cal = calendar.Calendar()
    for year in range(from_year,to_year+1):
        for month in range(1,13):
            if calendar.weekday(year,month,1) == 0:
                ret += 1
            print((year,month))

    return ret

def main():
    print(count(1900,1,2000,12))

if __name__ == "__main__":
    main()


