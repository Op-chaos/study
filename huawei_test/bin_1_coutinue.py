# 统计一个数的二进制 数 1 的个数
num = str(bin(int(input())))
num = num[2:]
length = len(num)
for i in range(length,0,-1):
    if '1'*i in num:
        print(i)
        break
print(num)
