import math

a, b, c = map(int, input().split())

s = (a + b + c) / 2

print(math.sqrt(s * (s - a) * (s - b) * (s - c)) / 4)