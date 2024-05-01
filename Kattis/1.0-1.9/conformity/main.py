from collections import Counter
_,*a=open(0)
c=Counter(frozenset(l.split())for l in a)
m=max(c.values())
print(list(c.values()).count(m)*m)
