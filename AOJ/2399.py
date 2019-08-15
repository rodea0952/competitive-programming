while 1:
    n = int(input())
    if n == 0:
        break

    p = []
    for i in range(n):
        lst = list(map(int, input().split()))[1:]
        p.append(lst)

    l = list(map(int, input().split()))[1:]

    ans = 0
    id = -1
    for i in range(n):
        sum = 0
        for j in l:
            if p[i].count(j):
                sum += 1
        
        if sum == len(l):
            ans += 1
            id = i + 1
    
    if ans == 1:
        print(id)
    else:
        print(-1)
