import sys

n, m = map(int, input().split())
a = list(map(int, input().split()))

cnt = [0 for i in range(100001)]
for i in a: cnt[i] += 1

for i in range(100001):
    if cnt[i] >= (n + 1) / 2:
        print(i)
        sys.exit()

print('?')