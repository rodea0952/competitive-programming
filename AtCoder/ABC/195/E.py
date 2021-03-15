n = int(input())
s = input()
x = input()

dp = [[False for j in range(7)] for i in range(n + 1)]
dp[n][0] = True
base = 1
for i in range(n)[::-1]:
    cur = int(s[i]) * base % 7
    base = base * 10 % 7
    for j in range(7):
        if x[i] == 'T':
            dp[i][j] = dp[i + 1][j] or dp[i + 1][(cur + j) % 7]
        else:
            dp[i][j] = dp[i + 1][j] and dp[i + 1][(cur + j) % 7]

if dp[0][0]:
    print("Takahashi")
else:
    print("Aoki")