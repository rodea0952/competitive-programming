import sys

n = int(input())
s = input()

base = []
t = 'b'

for i in range(100):
    base.append(t)
    if i % 3 == 0: t = 'a' + t + 'c'
    elif i % 3 == 1: t = 'c' + t + 'a'
    else: t = 'b' + t + 'b'

for i in range(len(base)):
    if s == base[i]:
        print(i)
        sys.exit()

print(-1)
