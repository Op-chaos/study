# a={1,2,34},b={3,34,5},a=2
import re 
# a = input().split("},")
# A = a[0].split("{")
# B = A[1].split(',')
# print(A)
a="{12;},b={3,34,5},a=2"
# /^((?!some_text).)*$/
strin = re.findall(r"\w+",a)
# a = list(map(int,strin[0].split(',')))
# b = list(map(int,strin[1].split(',')))
# c = int(strin[2])
# print(a,b,c)
print(strin)