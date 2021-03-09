h, w = map(int, input().split())
s = [input() for i in range(h)]

ans = 0
for i in range(h):
    for j in range(w - 1):
        ans += (s[i][j] == '.' and s[i][j + 1] == '.')

for j in range(w):
    for i in range(h - 1):
        ans += (s[i][j] == '.' and s[i + 1][j] == '.')

print(ans)