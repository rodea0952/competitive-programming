s = input()
n = len(s)

ans = []
for i in range(n):
    if i + 1 < n and s[i] == s[i + 1]:
        continue
    ans.append(s[i])

print("".join(ans))