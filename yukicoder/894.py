import math

t, a, b = map(int, input().split())

t -= 1
l = a * b // math.gcd(a, b)

print(1 + t // a + t // b - t // l)