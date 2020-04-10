s = input()
t = input()

base = ['a', 't', 'c', 'o', 'd', 'e', 'r']

valid = True
for i in range(len(s)):
    if s[i] != t[i]:
        if s[i] == '@' and base.count(t[i]): continue
        if base.count(s[i]) and t[i] == '@': continue
        valid = False

if valid: print("You can win")
else: print("You will lose")