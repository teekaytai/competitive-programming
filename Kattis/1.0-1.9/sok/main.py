*a, = map(int, input().split())
*b, = map(int, input().split())
r = min(x/y for x, y in zip(a, b))
print(*(x-r*y for x,y in zip(a, b)))
