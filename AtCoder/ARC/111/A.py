n, m = map(int, input().split())

print(pow(10, n, m ** 3) // m % m)