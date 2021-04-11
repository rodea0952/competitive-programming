n = int(input())
a = list(map(int, input().split()))

cnt = [0] * 3
for i in a:
    if i == 1:
        cnt[0] += 1
    elif i == 2:
        cnt[1] += 1
    else:
        cnt[2] += 1

print(cnt[0] * (cnt[0] - 1) // 2 * 2 + cnt[0] * cnt[1] * 3 + cnt[0] * cnt[2] * 2 + cnt[1] * (cnt[1] - 1) // 2 + cnt[1] * cnt[2] + cnt[2] * (cnt[2] - 1) // 2)