n, m = map(int, input().split())

l = 30 * (n % 12) + m / 2
s = 6 * m

ans = abs(l - s)

if 180 < ans: print(360 - ans)
else: print(ans)