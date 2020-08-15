while True:
    try:
        n = int(input())
        names = []
        for i in range(n):
            names.append(input())

        for name in names:
            name_list = list(name)
            name_alp = set(name_list)
            l_name = len(name_alp)
            name_alp = list(name_alp)
            sum_alp = []
            print(name_list, name_alp, l_name,"\n")
            for i in range(l_name):
                print(2,name_list.count(name_alp[i]))
                sum_alp.append(name_list.count(name_alp[i]))
            print(3)
            sum_alp.sort(reverse=True)
            i = 26
            cnt = 0
            print(sum_alp)
            for alp_n in sum_alp:
                cnt = cnt + i * alp_n
                i = i-1
            print("%d\n"%cnt)

    except:
        print("error\n")
        break