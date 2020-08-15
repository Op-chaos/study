# -*- coding: utf-8 -*-
"""
Created on Mon Mar  2 10:00:36 2020

@author: neusoft
"""

while True:
    try:
        n, res = int(input()), set()
        for i in range(n):
            res.add(int(input()))
        for i in sorted(res, reverse = True):
            print(i)
    except:
        print("error")
        break;