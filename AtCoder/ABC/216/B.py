n = int(input())
s = []
t = []
for i in range(n):
    S, T = map(str, input().split())
    s.append(S)
    t.append(T)

for i in range(n):
    for j in range(i):
        if s[i] == s[j] and t[i] == t[j]:
            print("Yes")
            exit()

print("No")