x, y = map(int, input().split('.'))

print(x, end="")
if y <= 2:
    print("-")
elif 7 <= y:
    print("+")