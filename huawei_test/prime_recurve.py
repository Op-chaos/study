def isprime(num):
    a = 2
    while a**2 < num:
        if num % a == 0:
            return False
        else:
            a += 1
    return True


def findcouples(ji_num,match,used,ou):
    for i in range(len(ou)):
        if isprime(ji_num + ou[i]) and used[i] == 0:
            used[i] = 1
            if match[i] == 0 or findcouples(match[i],match,used,ou):
                match[i] = ji_num
                pass
    return True


def main():
    while True:
        try:
            n = input()
            numbers = list(map(int,input().split()))
            ji = []
            ou = []
            for i in numbers:
                if i % 2 == 0:
                    ou.append(i)
                else:
                    ji.append(i)
            OK_num = 0
            match =  [0] * len(ou)
            for i in ji:
                used = [0] * len(ou)
                print(match,used)
                is_find = findcouples(i,match,used,ou)
                if is_find == True:
                    OK_num += 1
            print("%d"%OK_num)

        except:
            print("error")
            break

if __name__ == "__main__":
    main()
