def insert_sort(alist):
    n = len(alist)
    for j in range(1, n):
        i = j
        while i > 0:
            if alist[i] < alist[i - 1]:
                alist[i], alist[i - 1] = alist[i - 1], alist[i]
                i -= 1
            else:
                break



if __name__ == '__main__':
    li = [54, 25, 41, 51, 2, 56, 23]
    print(li)
    insert_sort(li)
    print(li)
