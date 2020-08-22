n = int(input())
t = list(map(int, input().split()))

ans = []
num = [0, 2, 4, 5, 7, 9, 11]
for i in range(12):
    cur = []
    for j in num:
        cur.append((j + i) % 12)

    valid = True
    for j in t:
        if j not in cur:
            valid = False

    if valid:
        ans.append(i)

if len(ans) == 1:
    print(ans[0])
else:
    print(-1)