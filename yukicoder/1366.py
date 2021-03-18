def is_kadomatsu(a):
    if a[0] == a[1] or a[1] == a[2] or a[2] == a[0]:
        return False
    return max(a) == a[1] or min(a) == a[1]

a = list(map(int, input().split()))
b = list(map(int, input().split()))

valid = False
for i in range(3):
    for j in range(3):
        a[i], b[j] = b[j], a[i]
        if is_kadomatsu(a) and is_kadomatsu(b):
            valid = True
        a[i], b[j] = b[j], a[i]

if valid:
    print("Yes")
else:
    print("No")