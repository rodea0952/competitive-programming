def check(s):
    cnt = 0
    for i in s:
        cnt += 1 if i == '(' else -1

        if cnt < 0:
            return False

    return True if cnt == 0 else False

n = int(input())

ans = []
for bit in range(1 << n):
    cur = ""
    for i in range(n):
        cur += '(' if bit & (1 << i) else ')'

    if check(cur):
        ans.append(cur)

ans.sort()
for i in ans:
    print(i)