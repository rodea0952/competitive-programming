from decimal import Decimal
from math import gcd

x = Decimal(input())

x *= 10 ** 9
den = 10 ** 9
x = int(x)
g = gcd(x, den)
x //= g
den //= g

print("{}/{}".format(x, den))