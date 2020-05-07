a = int(input())

ans = -1
for i in range(10, 10001):

    digit1 = []
    num = i
    while num > 0:
        digit1.append(num % 10)
        num //= 10

    digit2 = []
    num = a
    while num > 0:
        digit2.append(num % i)
        num //= i

    if digit1 == digit2:
        ans = i

print(ans)