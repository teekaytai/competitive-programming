N = int(input())
primes = []
isp = [True] * N
isp[:2] = [False, False]
for i in range(2, N):
    if not isp[i]: continue
    primes.append(i)
    for j in range(i * 2, N, i):
        isp[j] = False
print(next(p for p in primes if N%p))
