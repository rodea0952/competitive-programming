a, v = map(int, input().split())
b, w = map(int, input().split())
t = int(input())

valid = False
if a < b:
    a += v * t
    b += w * t
    if b <= a:
        valid = True
else:
    a -= v * t
    b -= w * t
    if a <= b:
        valid = True

print("YES") if valid else print("NO")