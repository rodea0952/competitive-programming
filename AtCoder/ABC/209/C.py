mod = 10 ** 9 + 7

n = int(input())
c = list(map(int, input().split()))

c.sort()

ans = 1
for i in range(n):
    ans *= c[i] - i
    ans %= mod

print(ans)