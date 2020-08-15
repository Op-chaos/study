def select_sort(alist):
    n = len(alist)
    for j in range(n -1):
        min_index = j
        for i in range(j + 1, n):
            if alist[min_index] > alist[i]:
                min_index = i
        alist[j], alist[min_index] = alist[min_index], alist[j]


if __name__ == '__main__':
    li = [54, 25, 41, 51, 2, 56, 23]
    print(li)
    select_sort(li)
    print(li)

