a, b, c = map(int, input().split())
k = int(input())

need = 0
while b <= a:
    b *= 2
    need += 1

while c <= b:
    c *= 2
    need += 1

if need <= k:
    print("Yes")
else:
    print("No")
