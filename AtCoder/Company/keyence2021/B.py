n, k = map(int, input().split())
a = list(map(int, input().split()))

cnt = [0] * n
for i in a:
    cnt[i] += 1

ans = 0
for i in range(k):
    for j in range(n):
        if cnt[j] == 0:
            ans += j
            break
        else:
            cnt[j] -= 1

print(ans)