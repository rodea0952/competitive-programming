x, y = map(int, input().split())

if x == y:
    if x == 0:
        print(1, 1)
    else:
        print(-1)
else:
    if x < y:
        print(x + 2 * y, y)
    else:
        print(x, 2 * x + y)
