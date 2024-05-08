_, *a = map(int, open(0))
print(min(a[0]+a[-2], a[1]+a[-1], min((x+y for x,y in zip(a, a[2:])), default=20000)))
