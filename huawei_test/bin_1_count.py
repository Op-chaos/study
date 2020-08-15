# 二进制统计 1 的个数
while True:
    try:
        n = int(input())
        m = bin(n)
        cnt = m.count('1')
        print(cnt)
    except:
        break

print(str(bin(int(input()))).count("1"))