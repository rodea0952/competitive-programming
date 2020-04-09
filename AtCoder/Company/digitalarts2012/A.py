s = input().split()
n = int(input())
t = [input() for i in range(n)]

ans = []
for i in s:
    delete = False
    for j in t:
        if len(i) != len(j): continue

        same = True
        for k in range(len(i)):
            if j[k] == '*': continue
            if i[k] != j[k]: same = False

        if same: delete = True

    if delete: ans.append('*' * len(i))
    else: ans.append(i)

print(' '.join(ans))