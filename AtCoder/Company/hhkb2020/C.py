n = int(input())
p = list(map(int, input().split()))

used = [False for i in range(200010)]

idx = 0
for i in range(n):
    used[p[i]] = True
    while used[idx]:
        idx += 1
    print(idx)