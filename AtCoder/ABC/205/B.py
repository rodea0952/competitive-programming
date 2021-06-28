n = int(input())
a = list(map(int, input().split()))

a.sort()
valid = True

for i in range(n):
    if i + 1 != a[i]:
        valid = False

if valid:
    print("Yes")
else:
    print("No")