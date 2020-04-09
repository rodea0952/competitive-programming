s = input()
n = len(s)

ans = ""
i = 0
while i < n:
    cnt = 0
    cur = s[i]
    while i < n and cur == s[i]:
        i += 1
        cnt += 1
    ans += cur + str(cnt)

print(ans)