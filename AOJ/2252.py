r = []
r += ['y', 'u', 'i', 'o', 'p', 'h', 'j', 'k', 'l', 'n', 'm']

while 1:
    s = input()
    if s == '#':
        break
    
    ans = 0
    for i in range(len(s)-1):
        if r.count(s[i]) != r.count(s[i+1]):
            ans += 1

    print(ans)

