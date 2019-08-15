while 1:
    n, m = map(int, input().split())
    if n == 0:
        break

    a = list(map(int, input().split()))

    ans = 0
    for i in range(n):
        for j in range(i+1, n):
            if m < a[i] + a[j]:
                continue

            ans = max(ans, a[i] + a[j])

    if ans == 0:
        print("NONE")
    else:
        print(ans)
