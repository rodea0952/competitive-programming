n = int(input())

ans = 0
lb = 1
ub = 999
comma = 0
while True:
    if ub < n:
        ans += (ub - lb + 1) * comma
    else:
        ans += (n - lb + 1) * comma
        break
    comma += 1
    lb *= 1000
    ub *= 1000
    ub += 999

print(ans)