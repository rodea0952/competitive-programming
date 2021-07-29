n, a, x, y = map(int, input().split())

if a < n:
    print(a * x + (n - a) * y)
else:
    print(n * x)