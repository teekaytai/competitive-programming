d = dict(zip('ABCDEFGHIJKLMNOPQRSTUVWXYZ_,.?','.- -... -.-. -.. . ..-. --. .... .. .--- -.- .-.. -- -. --- .--. --.- .-. ... - ..- ...- .-- -..- -.-- --.. ..-- .-.- ---. ----'.split()))
D = {v: k for k, v in d.items()}
for l in map(str.strip, open(0)):
    a = [d[c] for c in l]
    c = [len(m) for m in a]
    c.reverse()
    s = ''.join(a)
    A = []
    i = 0
    for v in c:
        A.append(D[s[i:i+v]])
        i += v
    print(''.join(A))
