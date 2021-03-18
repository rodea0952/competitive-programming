n, k = map(int, input().split())

cnt = [0 for i in range(2 * n + 1)]
base = 0
for i in range(2, n + 2):
    cnt[i] = i - 1
    base = cnt[i] + i
for i in range(n + 2, 2 * n + 1):
    cnt[i] = base - i

ans = 0
for i in range(2, 2 * n + 1):
    if k + i <= 2 * n and 2 <= k + i:
        ans += cnt[i] * cnt[k + i]

print(ans)