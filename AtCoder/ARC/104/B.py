n, s = input().split()
n = int(n)

ans = 0
for i in range(n):
    AT = 0
    CG = 0
    for j in range(i, n):
        if s[j] == 'A': AT += 1
        elif s[j] == 'T': AT -= 1
        elif s[j] == 'C': CG += 1
        else: CG -= 1

        if AT == 0 and CG == 0: ans += 1

print(ans)