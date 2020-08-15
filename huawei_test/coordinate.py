# 坐标变化 A78;B5;C90;
while True:
    try:
        str1 = input().split(';')
        direction = {'A':1,'D':2,'W':3,'S':4}
        n = len(str1)
        print("%d"%n)
        x, y = 0, 0
        for i in range(n):
            tmp =str1[i]
            if not tmp:
                coutinue
            judge = direction.get(tmp[0], 0)
            if judge and len(tmp) <= 3:
                number = -1
            try:
                number = int(tmp[1:])
            except:
                pass
            if number >= 1:
                if judge == 1:
                    x -= number
                if judge == 2:
                    x += number
                if judge == 3:
                    y -= number
                if judge == 4:
                    y += number
        print("%d,%d"%(x,y))
    except:
        break
