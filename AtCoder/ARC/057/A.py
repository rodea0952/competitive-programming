a, k = map(int, input().split())

goal = 2 * 10**12

if k == 0:
    print(goal - a)
else:
    ans = 0
    while(a < goal):
        a += 1 + k * a
        ans += 1
    print(ans)