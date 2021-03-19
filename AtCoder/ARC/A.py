a, b, x, y = map(int, input().split())

print(x + min(abs(a - b), abs(a - 1 - b)) * min(2 * x, y))