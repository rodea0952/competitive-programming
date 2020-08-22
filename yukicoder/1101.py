v, t, p = map(int, input().split())

print((p + 1) * v + ((p + 1) * v - 1) // (t - 1) + 1)