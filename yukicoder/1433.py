n = int(input())
s = input()
a = list(map(int, input().split()))

dp1 = [0 for i in range(n + 1)]
dp2 = [0 for i in range(n + 1)]
for i in range(n):
    if s[i] == 'R':
        dp1[i + 1] = max(dp1[i + 1], dp1[i] - a[i])
        dp2[i + 1] = max(dp2[i + 1], dp2[i] + a[i])
    else:
        dp1[i + 1] = max(dp1[i + 1], dp1[i] + a[i])
        dp2[i + 1] = max(dp2[i + 1], dp2[i] - a[i])

print(max(max(dp1), max(dp2)))