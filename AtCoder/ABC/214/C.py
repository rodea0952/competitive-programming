n = int(input())
s = list(map(int, input().split()))
t = list(map(int, input().split()))

idx = t.index(min(t))

ans = [0] * n
pre = t[idx]
for i in range(n):
    cidx = (i + idx) % n
    ans[cidx] = min(pre, t[cidx])
    pre = min(pre, t[cidx]) + s[cidx]

for i in range(n):
    print(ans[i])