n, k = map(int, input().split())
s = input()

head = s[:k-1]

if (n + 1 - k) % 2 == 1: head = head[::-1]

print(s[k-1:] + head)