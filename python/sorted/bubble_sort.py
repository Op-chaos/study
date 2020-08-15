def bubble_sort(alist):
    n = len(alist)
    count = 0
    for i in range(n-1):
        for j in range(n - 1 - i):
            if alist[j] > alist[j +1]:
                alist[j], alist[j + 1] = alist[j + 1], alist[j]
                count += 1
            if 0 == count:
                return


if __name__ == '__main__':
    li = [54, 25, 41, 51, 2, 56, 23]
    print(li)
    bubble_sort(li)
    print(li)

