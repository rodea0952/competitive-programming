n = int(input())
t = input()

if t == '1':
    print(2 * 10 ** 10)
    exit()

s = ""
while len(s) <= n + 10:
    s += "110"

idx = s.find(t)
if idx == -1:
    print(0)
else:
    idx += n
    print((3 * 10 ** 10 - idx) // 3 + 1)