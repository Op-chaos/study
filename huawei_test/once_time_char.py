while True:
    try:
        str1 = input()
        flag =0;
        for i in str1:
            if str1.count(i) == 1:
                print(i)
                flag = 1
                break
        if flag == 0:
            print("-1")
    except:
        print("error")
        break