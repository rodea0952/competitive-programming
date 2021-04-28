p = int(input())

f = [1] * 10 ** 7

for i in range(1, 10 ** 7):
    if 3 <= i:
        f[i] = f[i - 1] + f[i - 2]
    f[i] %= p
    if f[i] == 0:
        print(i)
        exit()

print(-1)