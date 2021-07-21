n, k = map(int, input().split())
a = list(map(int, input().split()))
ai = []
for i in range(n):
    ai.append([a[i], i])

ai.sort()

ans = [k // n] * n
k %= n

for i in range(k):
    ans[ai[i][1]] += 1

for i in range(n):
    print(ans[i])