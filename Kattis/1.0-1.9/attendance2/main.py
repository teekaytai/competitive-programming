from itertools import zip_longest
_, *a = map(str.strip, open(0))
print(*[x for x, y in zip_longest(a, a[1:]) if x != 'Present!' != y] or ['No Absences'], sep='\n')
