import math

n = int(input())
x = list(map(int, input().split()))

prime = []
for i in range(2, 50):
    cnt = 0
    for j in range(1, i + 1):
        cnt += (i % j == 0)
    if cnt == 2:
        prime.append(i)

ans = 10 ** 18
for bit in range(1 << len(prime)):
    cur = 1
    for i in range(len(prime)):
        if bit & (1 << i):
            cur *= prime[i]

    valid = True
    for i in range(n):
        if math.gcd(x[i], cur) == 1:
            valid = False

    if valid:
        ans = min(ans, cur)

print(ans)