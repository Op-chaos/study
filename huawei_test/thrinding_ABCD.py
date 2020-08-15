while True:
    try:
        import threading
        n = int(input())
        str_alp = []
        def print_alp(alp):
            global str_alp
            str_alp.append(alp)
        for i in range(n):
            for a in ['A','B','C','D']:
                t = threading.Thread(target=print_alp,args=(a,))
                t.start()
                t.join()
        print(' '.join(str_alp))

    except:
        break