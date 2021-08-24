n = int(input())

k = 1
while 2 ** k <= n:
    k += 1

print(k - 1)