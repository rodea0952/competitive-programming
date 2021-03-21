import math

n = int(input())

ans = 1
for i in range(2, n + 1):
    ans = ans * i // math.gcd(ans, i)

print(ans + 1)