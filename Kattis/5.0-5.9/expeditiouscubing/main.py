from statistics import mean
*a, t = map(float, open(0).read().split())
a.sort()
if mean(a[:3]) > t: print('impossible')
elif mean(a[1:]) <= t: print('infinite')
else: print(f'{t * 3 - a[1] - a[2]:.2f}')
