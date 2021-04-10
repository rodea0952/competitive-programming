n, k = map(int, input().split())
a = list(map(int, input().split()))

ans = set()
for bit in range(1 << n):
    if bin(bit).count('1') < k:
        continue

    sum = 0
    pro = 1
    for i in range(n):
        if bit & (1 << i):
            sum += a[i]
            pro *= a[i]

    ans.add(sum)
    ans.add(pro)

print(len(ans))