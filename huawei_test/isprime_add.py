import math

def isprime(n):
    for i in range(2,int(math.sqrt(n))+1):
        if n % i == 0:
            return False
    return True

while True:
    try:
        n = int(input())
        for i in range(int(n/2)+1,n):
            if isprime(i)==True and isprime(n-i)==True:
                print(n-i)
                print(i)
                break
    except:
        print("error")
        break