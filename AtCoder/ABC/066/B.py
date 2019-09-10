s = input()
n = len(s)

for i in range(n-2)[::-2]:
    half = i // 2
    head = s[0:half+1]
    tail = s[half+1:i+1]
    if head == tail:
        print(i+1)
        break
