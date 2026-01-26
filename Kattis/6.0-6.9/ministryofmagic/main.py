from collections import Counter
(n, m), *a = [[int(x) for x in l.split()] for l in open(0)]
bs = [True] * (n + 1)
t = n
I = [1] * m
while t:
    c = Counter()
    for i, l in enumerate(a):
        while not bs[l[I[i]]]:
            I[i] += 1
        c[l[I[i]]] += l[0]
    k, v = c.most_common(1)[0]
    if v > c.total() // 2:
        print(k)
        exit()
    if len(c) == t:
        i = min((v, k) for k, v in c.items())[1]
    else:
        i = next(i for i in range(1, n + 1) if i not in c and bs[i])
    bs[i] = False
    t -= 1
