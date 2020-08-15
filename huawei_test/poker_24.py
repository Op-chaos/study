str1= input().split(' ')
dictpoker = {'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,'9':9,'10':10,'J':11,'Q':12,'K':13,'A':1}
for i in range(len(str1)):
    num1[i] = dictpoker[str1[i]]

print(num1,num2)
if (joker in str1) or (JOKER in str1):
    print("error")
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
