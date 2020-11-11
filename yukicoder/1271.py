import math
import sys

k = int(input())

if k == 0:
    print(math.pi ** 2 / 6)
    sys.exit()

ans = 0
for i in range(1, k + 1):
    ans += 1 / i

print(ans / k)