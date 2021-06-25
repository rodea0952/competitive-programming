n = int(input())
a = list(map(int, input().split()))

ans = 0
for i in a:
    ans += max(0, i - 10)

print(ans)