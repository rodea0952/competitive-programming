n = int(input())
a = list(map(int, input().split()))

a.sort(reverse=True)

cnt = 0
k = 0
ans = 0
for i in range(n):
    ans += a[i] * k
    cnt += 1
    if cnt == 2 ** k:
        k += 1
        cnt = 0

print(ans)