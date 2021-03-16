import numpy as np

t = int(input())

for i in range(t):
    abc = list(map(int, input().split()))
    ans = np.prod(abc)
    print(ans, ans, ans)