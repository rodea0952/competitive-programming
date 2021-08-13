n = int(input())
a = list(map(int, input().split()))

A = []
for i in range(n):
    A.append([a[i], i])

A.sort()

print(A[n - 2][1] + 1)