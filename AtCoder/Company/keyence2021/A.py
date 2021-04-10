n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

amax = [0] * n
amax[0] = a[0]
for i in range(1, n):
    amax[i] = max(amax[i - 1], a[i])

dp = [0] * (n + 1)
for i in range(n):
    dp[i + 1] = max(dp[i], b[i] * amax[i])

for i in range(1, n + 1):
    print(dp[i])