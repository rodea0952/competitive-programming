n = int(input())
k = list(map(int, input().split()))

k2 = [10**9]
for i in k: k2.append(i)
k2.append(10**9)

ans = []
for i in range(len(k2)-1):
    ans.append(min(k2[i], k2[i+1]))

print(*ans)