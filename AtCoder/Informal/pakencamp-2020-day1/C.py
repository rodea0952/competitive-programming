from collections import defaultdict

n = int(input())
cnt = defaultdict(int)
for i in range(n):
    k = int(input())
    s = list(input().split())
    for j in s:
        cnt[j] += 1

ans = 0
for i in cnt:
    ans += cnt[i] == n

print(ans)