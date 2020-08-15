# 认为 merge_sort 的 返回值是有序序列
def merge_sort(alist):
    if len(alist) <= 1:
        return alist
    # 二分分解
    num = len(alist) // 2
    # 两边进行排序得到新的有序序列 left 和 right
    left = merge_sort(alist[:num])
    right = merge_sort(alist[num:])

    return merge(left, right)


def merge(left, right):
    """合并操作， 将两个有序数组left 和 right[] 合并成一个大的有序数组"""
    # left 与 right 的下标
    left_pointer, right_pointer = 0, 0
    result = []

    while left_pointer < len(left) and right_pointer < len(right):
        if left[left_pointer] < right[right_pointer]:
            result.append(left[left_pointer])
            left_pointer += 1
        else:
            result.append(right[right_pointer])
            right_pointer += 1

    result += left[left_pointer:]
    result += right[right_pointer:]

    return result


if __name__ == '__main__':
    li = [54, 25, 41, 51, 2, 56, 23]
    print(li)
    li = merge_sort(li)
    print(li)

