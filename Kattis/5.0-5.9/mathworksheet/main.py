first = True
while n := int(input()):
    if first:
        first = False
    else:
        print()
    a = [eval(input()) for _ in range(n)]
    w = max(len(str(x)) for x in a)
    l = 51 // (w+1)
    for i in range(0, len(a), l):
        print(*(f'{x:>{w}}' for x in a[i:i+l]))
