n, q = map(int, input().split())
s = input()

alpsum = [[0 for j in range(26)] for i in range(n + 1)]
for i in range(n):
    for j in range(26):
        alpsum[i + 1][j] += alpsum[i][j] + (j == ord(s[i]) - 97)

for i in range(q):
    l, r, x = map(int, input().split())
    l -= 1
    r -= 1
    for j in range(26):
        if alpsum[r + 1][j] - alpsum[l][j] >= x:
            print(chr(j + 97))
            break
        else:
            x -= alpsum[r + 1][j] - alpsum[l][j]