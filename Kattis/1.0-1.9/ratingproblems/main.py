a, b, *c = map(int, open(0).read().split())
s=sum(c)
print((s-3*(a-b))/a,(s+3*(a-b))/a)
