while True:
    try:
        a,b = input().split()
        print("%s"%a[:int(b)])
    except:
        break