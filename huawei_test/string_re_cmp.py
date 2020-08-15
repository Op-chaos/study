import re
s = input().split(' ')
len1 = len(s[0])
len2 = len(s[1])
fd = 0
if len1 < len2:
    for i in range(len1,0,-1):
        for start in range(len1 - i + 1):
            if re.findall(s[0][start:start+i],s[1]):
                print(i)
                fd = 1
                break
        if fd == 1:
            break