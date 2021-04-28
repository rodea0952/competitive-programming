n, l = map(int, input().split())
k = int(input())
a = list(map(int, input().split()))

ok = 1
ng = 10 ** 9
while ng - ok > 1:
    mid = (ok + ng) // 2
    pre = 0
    cnt = 0
    for i in range(n):
        if mid <= a[i] - pre:
            pre = a[i]
            cnt += 1
    if mid <= l - pre:
        cnt += 1
    
    if k + 1 <= cnt:
        ok = mid
    else:
        ng = mid

print(ok)