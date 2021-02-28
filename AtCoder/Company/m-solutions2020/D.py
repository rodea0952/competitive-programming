n = int(input())
a = list(map(int, input().split()))

sum = 1000
for i in range(n - 1):
    if a[i] >= a[i + 1]:
        continue

    sum += sum // a[i] * (a[i + 1] - a[i])

print(sum)