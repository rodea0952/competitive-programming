a, b = map(int, input().split())

ans = min(a, b) * 2
if a == b: ans -= 1

print(ans)