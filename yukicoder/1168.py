n = int(input())

for i in range(100):
    s = str(n)
    a = list(map(int, s))
    n = sum(a)

print(n)