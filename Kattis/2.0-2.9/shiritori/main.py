_, *a = map(str.strip, open(0))
s = set()
i = 1
p = a[0][0]
for l in a:
    if l[0] != p or l in s: print('Player', i, 'lost'); break
    s.add(l)
    p = l[-1]
    i = 3-i
else:
    print('Fair Game')
