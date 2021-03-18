import queue

n = int(input())
G = [[] for i in range(n)]
for i in range(n - 1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    G[a].append(b)
    G[b].append(a)

deg3 = 0
cv = -1
for i in range(n):
    if 3 <= len(G[i]):
        deg3 += 1
        cv = i

if deg3 >= 2:
    print("No")
    exit()

if deg3 == 0:
    print("Yes")
    exit()

que = queue.Queue()
que.put([cv, 0])
visited = [False for i in range(n)]
visited[cv] = True
leaf = set()
while not que.empty():
    cv, d = que.get()
    is_leaf = True
    for nv in G[cv]:
        if visited[nv]: continue
        visited[nv] = True
        is_leaf = False
        que.put([nv, d + 1])

    if is_leaf: leaf.add(d)

if len(leaf) == 1:
    print("Yes")
else:
    print("No")