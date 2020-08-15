while True:
    try:
        a,b,c = int(input()), 0,[]
        for i in range(4, a+1):
            for j in range(1, int(i *0.5)+ 1):
                if i % j ==0 :
                    b += j
            if b==i:
                c.append(i)
            b = 0

        print(len(c))

    except:
        print("error")
        break