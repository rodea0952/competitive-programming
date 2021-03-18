a, b, c = map(int, input().split())

a = a * (a + 1) // 2
b = b * (b + 1) // 2
c = c * (c + 1) // 2

print(a * b * c % 998244353)