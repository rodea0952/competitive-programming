n = int(input())

ok = 1
ng = 10 ** 10
while ng - ok > 1:
    mid = (ok + ng) // 2
    s = mid * (mid + 1) // 2
    if s <= n + 1: ok = mid
    else: ng = mid

print(n + 1 - ok)
