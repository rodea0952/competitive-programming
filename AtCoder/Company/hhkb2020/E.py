MOD = 10**9 + 7

h, w = map(int, input().split())
s = [input() for i in range(h)]

wcnt = [[1 for j in range(w)] for i in range(h)]
for i in range(h):
    for j in range(1, w):
        if s[i][j - 1] == '.' and s[i][j] == '.':
            wcnt[i][j] = wcnt[i][j - 1] + 1

    for j in range(w - 2, -1, -1):
        if s[i][j + 1] == '.' and s[i][j] == '.':
            wcnt[i][j] = wcnt[i][j + 1]

hcnt = [[1 for j in range(w)] for i in range(h)]
for j in range(w):
    for i in range(1, h):
        if s[i - 1][j] == '.' and s[i][j] == '.':
            hcnt[i][j] = hcnt[i - 1][j] + 1

    for i in range(h - 2, -1, -1):
        if s[i + 1][j] == '.' and s[i][j] == '.':
            hcnt[i][j] = hcnt[i + 1][j]

all = 0
for i in range(h):
    for j in range(w):
        all += s[i][j] == '.'

pow2 = [1 for i in range(4000010)]
for i in range(4000005):
    pow2[i + 1] = pow2[i] * 2 % MOD

ans = 0
for i in range(h):
    for j in range(w):
        if s[i][j] == '#':
            continue

        cur = wcnt[i][j] + hcnt[i][j] - 1
        ans += pow2[all - cur] * (pow2[cur] - 1) + MOD
        ans %= MOD

print(ans)
