while True:
    try:
        num = int(input())
        weights = list(map(int,input().split()))
        cnt = list(map(int,input().split()))
        fms,tmp,set_fm = [],[],[0]
        for i in range(num):
            for j in range(cnt[i]):
                fms.append(weights[i])

        for i in fms:
            tmp = set(set_fm)
            for j in tmp:
                set_fm.append(i + j)
        print(set_fm)
        print(len(set(set_fm)))

    except:
        print("error")
        break