n = int(input())

sub = set()
for a in range(2, n + 1):
    if a ** 2 > n:
        break

    for b in range(2, 64):
        if a ** b > n:
            break

        sub.add(a ** b)

print(n - len(sub))