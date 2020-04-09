from collections import Counter

n = int(input())
d = Counter(list(map(int, input().split())))
m = int(input())
t = Counter(list(map(int, input().split())))

valid = True
for i in t:
    if d[i] < t[i]:
        valid = False

if valid: print("YES")
else: print("NO")