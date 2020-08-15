# 输入数据，判断这些数能否通过加减乘除，变成24
def helper(arr,item):
    if item < 1:
        return False
    if len(arr)==1:
        return arr[0] == item  # 
    for i in range(len(arr)):
        L=arr[:i]+arr[i+1:]
        v = arr[i]
        if helper(L,item -v) or helper(L,item + v) or helper(L,item / v) or helper(L,item * v):
            return True


while True:
    try:
        num = list(map(int,input().split()))
        if helper(arr,24):
            print("true")
        else:
            print("false")
    except:
        break