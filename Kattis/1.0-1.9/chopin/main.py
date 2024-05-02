a = 'A# C# D# F# G# Ab Gb Eb Db Bb'.split()
d=dict(zip(a, a[::-1]))
for i, l in enumerate(open(0)):
    x, y = l.split()
    print(f'Case {i+1}:', *[d.get(x), y]*(x in d) or['UNIQUE'])
