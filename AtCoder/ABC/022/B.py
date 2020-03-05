n = int(input())
a = [int(input()) for i in range(n)]
cnt = [0 for i in range(100001)]

for i in a:
    cnt[i] += 1

ans = 0
for i in range(1, 100001):
    ans += max(0, cnt[i] - 1)

print(ans)