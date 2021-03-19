n = int(input())
s = input()

seq = []
for i in range(n):
    seq.append(s[i])
    if len(seq) <= 2: continue
    if seq[-3] + seq[-2] + seq[-1] == "fox":
        for j in range(3):
            seq.pop()

print(len(seq))