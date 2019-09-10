l, x, y, s, d = map(int, input().split())

if y - x <= 0:
    if s <= d:
        dist = d - s
        print(dist / (x + y))
    else:
        dist = (l - s) + d
        print(dist / (x + y))
else:
    if s <= d:
        dist = d - s
        cdist = s + (l - d)
        print(min(dist / (x + y), cdist / (y - x)))
    else:
        dist = (l - s) + d
        cdist = s - d
        print(min(dist / (x + y), cdist / (y - x)))
