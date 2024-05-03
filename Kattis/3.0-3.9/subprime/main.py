N = 1300000
primes = []
isp = [True] * N
isp[:2] = [False, False]
for i in range(2, N):
    if not isp[i]: continue
    primes.append(i)
    for j in range(i * 2, N, i):
        isp[j] = False

l, h = map(int, input().split())
p = input()
print(sum(p in str(x) for x in primes[l-1:h]))
