n = int(input())
a = list(map(int, input().split()))

if n == 1:
    print(a[0])
    exit()

ans = 10 ** 10
for bit in range(1 << (n - 1)):
    aor = 0
    axor = 0
    for i in range(n):
        aor |= a[i]
        if (bit & (1 << i)) or i == n - 1:
            axor ^= aor
            aor = 0
    ans = min(ans, axor)

print(ans)