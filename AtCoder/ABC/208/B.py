p = int(input())

ans = 0
for i in range(10, 0, -1):
    cur = 1
    for j in range(1, i + 1):
        cur *= j
    ans += p // cur
    p %= cur

print(ans)