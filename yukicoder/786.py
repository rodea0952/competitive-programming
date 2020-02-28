n = int(input())

dp = [0 for i in range(n + 1)]
dp[1] = 1
dp[2] = 2

for i in range(2, n):
    dp[i + 1] = dp[i] + dp[i - 1]

print(dp[n])