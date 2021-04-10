import heapq

n, k = map(int, input().split())

dp = [10 ** 9] * (n + 1)
dp[1] = 0
que = [1]
heapq.heapify(que)
while len(que):
    cur = heapq.heappop(que)
    if cur * 2 <= n and dp[cur] + 1 < dp[cur * 2]:
        dp[cur * 2] = dp[cur] + 1
        heapq.heappush(que, cur * 2)
    if cur + 3 <= n and dp[cur] + 1 < dp[cur + 3]:
        dp[cur + 3] = dp[cur] + 1
        heapq.heappush(que, cur + 3)

print("YES") if dp[n] <= k else print("NO")