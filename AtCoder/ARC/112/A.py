n = int(input())
for i in range(n):
    l, r = map(int, input().split())
    if r < 2 * l:
        print(0)
    else:
        # 2 * l <= r
        x = r - 2 * l + 1
        print(x * (x + 1) // 2)