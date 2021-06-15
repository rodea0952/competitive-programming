n, k = map(int, input().split())
xy = [list(map(int, input().split())) for i in range(n)]
xy.sort()

for i in range(n):
    if k < xy[i][0]:
        break
    k += xy[i][1]

print(k)