N = 32001
primes = []
isp = [True] * N
isp[:2] = [False, False]
for i in range(2, N):
    if not isp[i]: continue
    primes.append(i)
    for j in range(i * 2, N, i):
        isp[j] = False

_, *a = map(int, open(0))
for x in a:
    r = []
    for p in primes:
        if p*2 > x: break
        if isp[x-p]: r.append(f'{p}+{x-p}')
    print(x, 'has', len(r), 'representation(s)')
    for l in r: print(l)
    print()
