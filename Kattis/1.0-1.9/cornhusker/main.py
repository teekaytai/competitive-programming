*a, = map(int, input().split())
p, q = map(int, input().split())
print(sum(x*y for x,y in zip(a[::2], a[1::2]))//5*p//q)
