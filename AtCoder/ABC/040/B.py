n = int(input())

ans = 10**9
for i in range(1, n + 1):
    a = i
    b = n // i
    ans = min(ans, abs(a - b) + n - a * b)

print(ans)