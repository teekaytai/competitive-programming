*a, t = [int(x.replace('.', '')) for x in open(0).read().split()]
t *= 3
a.sort()
if sum(a[:3]) > t: print('impossible')
elif sum(a[1:]) <= t: print('infinite')
else: print(f'{(t - a[1] - a[2]) / 100:.2f}')
