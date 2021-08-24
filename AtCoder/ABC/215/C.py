import itertools

s, k = map(str, input().split())
k = int(k)

candi = []
for i in itertools.permutations(s):
    candi.append(i)

candi = sorted(list(set(candi)))
print(''.join(candi[k - 1]))