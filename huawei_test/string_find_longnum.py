# 输出字符串中的最长数字
import re 
str1 = input()
length = len(str1)
flog =0
for i in range(length,0,-1):
    for start in range(length-i+1):
        try:
            str2 = str1[start:start+i]
            num = int(str2)
            print(str2,end=',')
            print(len(str2))
            flog =1
            break
        except:
            pass
    if flog==1:
        break