# 比较两手扑克大小
def isright(num):
    lenth = len(num)
    if lenth>4 and max(num) < 15:
        print(sum(num))
        print(min(num)*lenth+(lenth - 1)*lenth/2)
        if sum(num) == min(num)*lenth+(lenth - 1)*lenth/2:
            return True
        else:
            return False
    elif len(num) == 2 and num[0]+num[1]==33:
        return True
    elif min(num) == max(num):
        return True
    else:
        return False

str1, str2 = input().split('-')
num1, num2 = str1.split(' '),str2.split(' ')
dictpoker = {'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,'9':9,'10':10,'J':11,'Q':12,'K':13,'A':14,'2':15,'jaker':16,'JAKER':17}
for i in range(len(num1)):
    num1[i] = dictpoker[num1[i]]
for i in range(len(num2)):
    num2[i] = dictpoker[num2[i]]
print(num1,num2)
if (isright(num1) ==False) or isright(num2) == False:
    print("error")
    #break
elif str1 == 'jaker JAKER' or str2 == "jaker JAKER":
    print("jaker JAKER")
    # break
elif len(num1)==4 and ien(num2)==4:
    if sum(num1)>sum(num2):
        print(str1)
    else:
        print(str2)
elif len(num1)==4:
    print(str1)
elif len(num2)==4:
    print(str2)
elif len(num1)==len(num2):
    if min(num1) > min(num2):
        print(str1)
    else:
        print(str2)
else:
    print('error')
