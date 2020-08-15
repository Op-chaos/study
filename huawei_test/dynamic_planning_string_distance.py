while True:
    try:
        str1, str2 = input(), input()
        len1, len2 = int(len(str1))+1, int(len(str2))+1
        dp = [[ 0 for i in range(len2)] for j in range(len1)]
        for i in range(len1):
            dp[i][0] = i
        for j in range(len2):
            dp[0][j] = j
        for i in range(1,len1):
            for j in range(1,len2):
                dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1] + (str1[i-1] != str2[j-1]))
        print(dp)
    except:
        print("error")
        break