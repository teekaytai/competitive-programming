def f(w):
    if w[0] in 'aeiouy': return w + 'yay'
    i = next(i for i in range(len(w)) if w[i] in 'aeiouy')
    return w[i:] + w[:i] + 'ay'
for l in open(0):
    print(*map(f, l.split()))
