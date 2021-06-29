n = int(input())

ng = 0
ok = 10**9

while ok - ng > 1:
    mid = (ng + ok) // 2
    if n <= mid * (mid + 1) // 2:
        ok = mid
    else:
        ng = mid

print(ok)