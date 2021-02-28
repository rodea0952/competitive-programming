n = int(input())

ans = 10 ** 9 + 1
for i in range(n):
    a, p, x = map(int, input().split())
    if a < x:
        ans = min(ans, p)

if 10 ** 9 < ans:
    print(-1)
else:
    print(ans)