import queue

n = int(input())

dp = [1e9 for i in range(n + 1)]

que = queue.Queue()
que.put(1)
dp[1] = 1

while not que.empty():
    cur = que.get()
    bit = bin(cur).count('1')
    
    plus = cur + bit
    if plus <= n and dp[cur] + 1 < dp[plus]:
        dp[plus] = dp[cur] + 1
        que.put(plus)    

    minus = cur - bit
    if 1 < minus and dp[cur] + 1 < dp[minus]:
        dp[minus] = dp[cur] + 1
        que.put(minus)

if dp[n] == 1e9: print(-1)
else: print(dp[n])