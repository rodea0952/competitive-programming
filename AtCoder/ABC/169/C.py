import math

a, b = map(float, input().split())
b *= 100

print(int(a * b // 100))