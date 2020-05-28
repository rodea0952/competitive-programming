import sys
import math

n = int(input())

if n == 1:
    print(1)
    sys.exit()

a = []
num = 100001
while len(a) < 10:
    is_prime = True
    for i in range(2, int(math.sqrt(num))+1):
        if num % i == 0: is_prime = False

    if is_prime:
        a.append(num)
    num += 1

b = a
c = set()

for i in a:
    for j in b:
        c.add(i * j)

c = sorted(c)
cnt = 2
for i in c:
    if cnt == n:
        print(i)
    cnt += 1