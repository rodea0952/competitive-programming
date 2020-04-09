import itertools

n, m, l = map(int, input().split())
a = list(map(int, input().split()))

per = list(itertools.permutations(range(3)))

ans = 0
for i in per:
    val1 = n // a[i[0]]
    val2 = m // a[i[1]]
    val3 = l // a[i[2]]
    ans = max(ans, val1 * val2 * val3)

print(ans)