import bisect

n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

b.sort()

ans = 10 ** 18
for i in a:
    l = max(0, bisect.bisect_left(b, i) - 1)
    mid = min(m - 1, bisect.bisect_left(b, i))
    r = min(m - 1, bisect.bisect_right(b, i))
    ans = min(ans, abs(i - b[l]), abs(i - b[r]), abs(i - b[mid]))

print(ans)