def findABBA(str1):
    length = len(str1)
    find =0
    for i in range(length,0,-1):
        for start in range(length-i+1):
            fd = str1[start:i+start]
            rfd = fd[::-1]
            destin = str1[start+i-1:]
            print(rfd,destin,'\n')
            if rfd in destin:
                if fd+rfd in str1:
                    print(2*i)
                else:
                    print(i*2-1)
                print(rfd,destin,'\n')
                find = 1
                break
        if find ==1:
            break

str1 = input()
findABBA(str1)

# while True:
#     try:
#         str1 = input()
#         findABBA(str1)
#     except:
#         break