a = list(map(int, input().split()))

valid = False
for bit in range(1 << 4):
    eat = 0
    for i in range(4):
        if bit & (1 << i):
            eat += a[i]

    if eat == sum(a) - eat:
        valid = True

if valid:
    print("Yes")
else:
    print("No")