def fenfa(apple,pan):
    if apple == 0 or pan ==1:
        return 1
    elif pan> apple:
        return fenfa(apple,apple)
    else:
        # fenfa(apple-pan,pan) 没有空盘子的情况，fenfa(apple,pan-1)有一个空盘子的情况
        return fenfa(apple-pan,pan)+fenfa(apple,pan-1)

while True:
    try:
        apple,pan = list(map(int,input().split()))
        print(fenfa(apple,pan))
    except:
        break