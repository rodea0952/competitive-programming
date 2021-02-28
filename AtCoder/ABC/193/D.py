k = int(input())
s = input()
t = input()

rest = [k for i in range(10)]
tak = [0 for i in range(10)]
aok = [0 for i in range(10)]

for i in range(4):
    rest[int(s[i])] -= 1
    rest[int(t[i])] -= 1
    tak[int(s[i])] += 1
    aok[int(t[i])] += 1

ans = 0
for x in range(1, 10):
    for y in range(1, 10):
        if rest[x] < 1 or rest[y] < 1 or (x == y and rest[x] < 2):
            continue
    
        tak[x] += 1
        aok[y] += 1

        tsum = 0
        asum = 0
        for i in range(1, 10):
            tsum += i * 10 ** tak[i]
            asum += i * 10 ** aok[i]

        tak[x] -= 1
        aok[y] -= 1

        if tsum > asum:
            ans += rest[x] * (rest[y] - (x == y)) / (9 * k - 8) / (9 * k - 9)

print(ans)