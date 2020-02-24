n = int(input())
ans = [0] * 6

for i in range(n):
    h, l = map(float, input().split())
    
    if 35 <= h: ans[0] += 1
    if 30 <= h and h < 35: ans[1] += 1
    if 25 <= h and h < 30: ans[2] += 1
    if 25 <= l: ans[3] += 1
    if l < 0 and 0 <= h: ans[4] += 1
    if h < 0: ans[5] += 1

ans = [str(i) for i in ans]
ans = ' '.join(ans)
print(ans)