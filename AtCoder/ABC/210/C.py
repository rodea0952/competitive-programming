from collections import defaultdict

n, k = map(int, input().split())
c = list(map(int, input().split()))

cnt = defaultdict(int)
st = set()

for i in range(k):
    cnt[c[i]] += 1
    st.add(c[i])

ans = len(st)
for i in range(k, n):
    cnt[c[i]] += 1
    st.add(c[i])
    cnt[c[i - k]] -= 1
    if cnt[c[i - k]] == 0:
        st.discard(c[i - k])
    ans = max(ans, len(st))

print(ans)