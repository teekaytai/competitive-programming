_, *a = open(0)
s = sorted(a)
print('INCREASING' if a==s else 'DECREASING' if a==s[::-1] else 'NEITHER')
