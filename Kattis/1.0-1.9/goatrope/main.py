from math import hypot
a,b,c,d,e,f = map(int, input().split())
def g(p,q,r):
    q,r=sorted((q,r))
    if p < q:return q-p
    if p > r:return p-r
    return 0
print(hypot(g(a,c,e),g(b,d,f)))
