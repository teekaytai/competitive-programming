*a, _ = open(0)
f = lambda c, d: 1000*(c+d==3) + 100*(c==d)*c + 10*max(c,d)+min(c,d)
for l in a:
    p, q, r, s = map(int, l.split())
    x = f(p, q)
    y = f(r, s)
    print(['Player 1 wins.', 'Tie.', 'Player 2 wins.'][(y>x)+(y>=x)])
