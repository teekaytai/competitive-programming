s = input()
n = len(s)
l1 = list('..#.') * n + ['.']
l2 = list('.#.#') * n + ['.']
l3 = list('#. .') * n + ['#']
for i in range(2, n, 3):
    l1[4*i+2] = '*'
    l2[4*i+1] = '*'
    l2[4*i+3] = '*'
    l3[4*i] = '*'
    l3[4*i+4] = '*'
for i, c in enumerate(s):
    l3[4*i+2] = c
print(''.join(l1))
print(''.join(l2))
print(''.join(l3))
print(''.join(l2))
print(''.join(l1))
