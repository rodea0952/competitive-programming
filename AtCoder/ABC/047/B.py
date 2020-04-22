w, h, n = map(int, input().split())

l = 0
r = w
d = 0
u = h

for i in range(n):
    x, y, a = map(int, input().split())
    if a == 1: l = max(l, x)
    if a == 2: r = min(r, x)
    if a == 3: d = max(d, y)
    if a == 4: u = min(u, y)

ans = max(0, r - l) * max(0, u - d)

print(ans)