n, k = map(int, input().split())
s = input()

same = 0
for i in range(n-1):
    if s[i] == s[i+1]:
        same += 1

print(min(n - 1, same + 2 * k))