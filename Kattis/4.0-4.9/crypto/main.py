N = 1000001
primes = []
isp = [True] * N
isp[:2] = [False, False]
for i in range(2, N):
    if not isp[i]: continue
    primes.append(i)
    for j in range(i * 2, N, i):
        isp[j] = False

n = int(input())
m = 1, -n
for p in primes:
    x = 0
    c = n
    while c % p == 0: c//=p; x+=1
    m = max(m, (x, -p))
print(-m[1])
