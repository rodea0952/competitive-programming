n = int(input())

ans = 0
for t in range(0, 101):
    for g in range(0, t + 1):
        for pg in range(0, 101):
            if t * 5 + g * 2 + pg * 3 == n:
                ans += 1

print(ans)