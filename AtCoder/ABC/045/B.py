sa = input()
sb = input()
sc = input()

turn = 0
aidx = 0
bidx = 0
cidx = 0
while True:
    if turn == 0:
        if len(sa) <= aidx:
            print("A")
            break

        nxt = sa[aidx]
        aidx += 1
    elif turn == 1:
        if len(sb) <= bidx:
            print("B")
            break

        nxt = sb[bidx]
        bidx += 1
    else:
        if len(sc) <= cidx:
            print("C")
            break

        nxt = sc[cidx]
        cidx += 1
    
    if nxt == 'a':
        turn = 0
    elif nxt == 'b':
        turn = 1
    else:
        turn = 2