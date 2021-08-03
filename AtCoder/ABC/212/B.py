s = input()

weak = False
if len(set(s)) == 1:
    weak = True

for i in range(10):
    cur = ""
    for j in range(4):
        cur += str((i + j) % 10)
    if s == cur:
        weak = True

if weak:
    print("Weak")
else:
    print("Strong")