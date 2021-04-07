n, k = map(int, input().split())
a = list(map(int, input().split()))

for i in range(min(k, 100)):
    imos = [0 for j in range(n + 1)]
    for j in range(n):
        imos[max(0, j - a[j])] += 1
        imos[min(n, j + a[j] + 1)] -= 1

    for j in range(n):
        imos[j + 1] += imos[j]
        a[j] = imos[j]

print(*a)