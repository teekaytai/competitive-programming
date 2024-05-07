n, m = map(int, input().split())
d = dict(input().split() for _ in range(n))
D = {'c': 'amount of least less much little', 'm': 'number of fewest fewer many few'}
for _ in range(m):
    a, b = input().rsplit(maxsplit=1)
    print(['Correct!', 'Not on my watch!'][a in D[d[b]]])
