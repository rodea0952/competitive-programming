n, m, q = map(int, input().split())
wv = [list(map(int, input().split())) for i in range(n)]
x = list(map(int, input().split()))

wv.sort(key=lambda x:x[1], reverse=True)

for i in range(q):
    l, r = map(int, input().split())

    box = sorted(x[:l - 1] + x[r:])
    ans = 0
    used = [False for j in range(n)]
    for j in box:
        for k in range(n):
            if not(used[k] or j < wv[k][0]):
                used[k] = True
                ans += wv[k][1]
                break

    print(ans)