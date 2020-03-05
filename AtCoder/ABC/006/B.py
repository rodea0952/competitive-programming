n = int(input())

dp = [0 for i in range(1000010)]
dp[3] = 1

for i in range(4, n + 1):
    dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3]
    dp[i] %= 10007

print(dp[n])