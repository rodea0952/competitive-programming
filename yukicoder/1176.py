a = int(input())

ans = 1e18
for i in range(2, 10):
    for j in range(1, 70):
        if a <= pow(i, j):
            ans = min(ans, i * j)

print(ans)