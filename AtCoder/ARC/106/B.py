import queue

n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

G = [[] for i in range(n)]
for i in range(m):
    c, d = map(int, input().split())
    c -= 1
    d -= 1
    G[c].append(d)
    G[d].append(c)

valid = True
visited = [False for i in range(n)]
for i in range(n):
    if visited[i]: continue
    visited[i] = True
    que = queue.Queue()
    que.put(i)
    sum = 0
    while not que.empty():
        cv = que.get()
        sum += a[cv] - b[cv]
        for nv in G[cv]:
            if visited[nv]: continue
            visited[nv] = True
            que.put(nv)
        
    if sum != 0:
        valid = False

if valid:
    print("Yes")
else:
    print("No")
