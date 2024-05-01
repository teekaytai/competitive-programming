from itertools import cycle, starmap
input()
s=input()
a=[sum(starmap(str.__eq__, zip(cycle(seq), s))) for seq in ('ABC','BABC','CCAABB')]
print(m:=max(a))
for x, n in zip(a, ['Adrian', 'Bruno', 'Goran']):
    if x == m:print(n)
