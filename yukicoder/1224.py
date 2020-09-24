import math

a, b = map(int, input().split())
GCD = math.gcd(a, b)
a //= GCD
b //= GCD

while b % 2 == 0:
    b //= 2

while b % 5 == 0:
    b //= 5

if b == 1:
    print("No")
else:
    print("Yes")