a, b, k, l = map(int, input().split())

print(min((k // l) * b + (k % l) * a, ((k + l - 1) // l) * b))