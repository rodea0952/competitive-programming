# a(n) = floor((n^2+3)/12) + floor((n+2)/2)
n = int(input())
n -= 4

ans = ((n**2 + 3) // 12) + ((n + 2) // 2)

print(ans % 1000000007)