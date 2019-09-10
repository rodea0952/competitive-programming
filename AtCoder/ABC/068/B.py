n = int(input())

num = [1, 2, 4, 8, 16, 32, 64]

for i in range(n+1)[::-1]:
    if num.count(i):
        print(i)
        break
