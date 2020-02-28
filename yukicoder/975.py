x, n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

ans = -1
if x in a and x in b: ans = "MrMaxValu"
elif x in a: ans = "MrMax"
elif x in b: ans = "MaxValu"

print(ans)