n, m = map(int, input().split())

if m == 0:
    l = 1
    r = 2
    for i in range(n):
        print(l, r)
        l += 2
        r += 2
    exit()

if n - 1 <= m or m < 0:
    print(-1)
    exit()

# 1 <= m <= n - 2
ans = [[1, 10 ** 6]]
l = 2
r = 3
for i in range(m + 1):
    ans.append([l, r])
    l += 2
    r += 2

l = 10 ** 6 + 1
r = 10 ** 6 + 2
for i in range(m + 1, n - 1):
    ans.append([l, r])
    l += 2
    r += 2

for i in ans:
    print(i[0], i[1])