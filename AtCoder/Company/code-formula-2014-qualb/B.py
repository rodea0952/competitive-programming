n = input()
n = n[::-1]

o = 0
e = 0
for i in range(len(n)):
    if i % 2 == 0: o += int(n[i])
    else: e += int(n[i])

print(e, o)