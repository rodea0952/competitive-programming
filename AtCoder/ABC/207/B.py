a, b, c, d = map(int, input().split())

ng = 0
ok = 10 ** 18
while ok - ng > 1:
    mid = (ng + ok) // 2
    if (a + b * mid) <= d * c * mid:
        ok = mid
    else:
        ng = mid

if ok == 10 ** 18:
    ok = -1

print(ok)