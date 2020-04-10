s = input()

ans = ""
for i in s:
    if i == 'B':
        if len(ans):
            ans = ans[:len(ans) - 1]
    else:
        ans += i

print(ans)