s, p = map(int, input().split())

for i in range(1, p + 1):
    if i * i > p: break
    if p % i == 0 and i + p // i == s:
        print("Yes")
        exit()

print("No")