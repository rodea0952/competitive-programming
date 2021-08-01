base = ["H", "2B", "3B", "HR"]

s = [0] * 4
for i in range(4):
    s[i] = input()

base.sort()
s.sort()

if base == s:
    print("Yes")
else:
    print("No")