#5 13124 最长方案124
def fd(nums):
    n = len(nums)
    dp = [1]*n  # 以第i个桩为结尾，最多走多少步，每一个初始为1
    res = 0
    for i in range(n):  # i表示第几个桩
        for j in range(i):  # j 表示前面的桩
            if nums[j] < nums[i]:
                dp[i] = max(dp[i],dp[j]+1)  # 依次从左到右统计出最大排列
    
    return max(dp)   # 返回最大的排序



n = int(input())
ns = list(map(int, input().split()))
print(ns)
print("最短：", fd(ns))

