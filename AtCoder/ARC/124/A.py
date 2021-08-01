MOD = 998244353

N, K = map(int, input().split())
c = [0] * K
k = [0] * K
for i in range(K):
    c[i], k[i] = map(str, input().split())
    k[i] = int(k[i])
    k[i] -= 1

used = [False] * N
cnt = [K] * N
for i in range(K):
    used[k[i]] = True
    if c[i] == 'R':
        for j in range(k[i] + 1, N):
            cnt[j] -= 1
    else:
        for j in range(0, k[i]):
            cnt[j] -= 1

ans = 1
for i in range(N):
    if used[i]:
        continue
    ans *= cnt[i]
    ans %= MOD

print(ans)