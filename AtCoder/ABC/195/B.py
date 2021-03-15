a, b, w = map(int, input().split())

w *= 1000
lb = (w + b - 1) // b
ub = w // a

if lb > ub:
    print("UNSATISFIABLE")
else:
    print(lb, ub)