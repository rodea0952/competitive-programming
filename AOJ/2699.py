import math

while 1:
    d, e = map(int, input().split())
    if d == 0:
        break

    ans = 1e9
    for i in range(d):
        x = i
        y = d - x
        dist = math.sqrt(x**2 + y**2)
        ans = min(ans, abs(dist - e))

    print(ans)
