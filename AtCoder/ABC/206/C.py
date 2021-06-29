from collections import defaultdict

n = int(input())
a = list(map(int, input().split()))

cnt = defaultdict(int)
for i in a:
    cnt[i] += 1

ans = n * (n - 1) // 2
for i in cnt:
    ans -= cnt[i] * (cnt[i] - 1) // 2

print(ans)