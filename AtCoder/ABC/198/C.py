r, x, y = map(int, input().split())

if x * x + y * y < r * r:
    print(2)
    exit()

ng = 0
ok = 10 ** 18
while ok - ng > 1:
    mid = (ok + ng) // 2
    if x * x + y * y <= r * r * mid * mid:
        ok = mid
    else:
        ng = mid

print(ok)