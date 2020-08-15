def quick_sort(alist, first, last):
    if first >= last:
        return
    mid_value = alist[first]
    low = first
    high = last

    while low < high:
        # 先high 左移动
        while low < high and alist[high] >= mid_value:
            high -= 1
        alist[low] = alist[high]

        # 再 low 右移动
        while low < high and alist[low] < mid_value:
            low += 1
        alist[high] = alist[low]
    # 从循环出来是 low = high
    alist[low] = mid_value
    # 对左边进行排序
    quick_sort(alist, first, low - 1)
    # 对右边进行排序
    quick_sort(alist, low + 1, last)


if __name__ == '__main__':
    li = [54, 25, 41, 51, 2, 56, 23]
    print(li)
    quick_sort(li, 0, len(li)-1)
    print(li)
