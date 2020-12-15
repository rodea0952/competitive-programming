import sys
n = int(input())
a = list(map(int,input().split()))

if a.count(0):
    print(0)
    sys.exit()

ans = 1
for i in a:
    ans *= i
    if 10**18 < ans:
        print(-1)
        sys.exit()

print(ans)