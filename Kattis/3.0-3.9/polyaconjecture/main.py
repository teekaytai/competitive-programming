d = int(input()) + 1
N = 1000002
primes = []
mnp = [0] * N
for i in range(2, N):
    if mnp[i] == 0:
        mnp[i] = i
        primes.append(i)
    for p in primes:
        j = i * p
        if p > mnp[i] or j >= N:
            break
        mnp[j] = p
    x = i
    c = 1
    while x > 1:
        x //= mnp[x]
        c = -c
    d += c
    if d == 0:
        print(i)
        exit()
