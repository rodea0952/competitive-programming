n = int(input())
t = [0] * n
l = [0] * n
r = [0] * n
for i in range(n):
    t[i], l[i], r[i] = map(int, input().split())
    l[i] *= 2
    r[i] *= 2
    if t[i] == 2:
        r[i] -= 1
    elif t[i] == 3:
        l[i] += 1
    elif t[i] == 4:
        l[i] += 1
        r[i] -= 1

ans = 0
for i in range(n):
    for j in range(i):
        if l[j] <= r[i] and l[i] <= r[j]:
            ans += 1

print(ans)
