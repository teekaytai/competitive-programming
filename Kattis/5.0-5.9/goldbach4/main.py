import random

def ispp(n, k=5):
    # Miller-Rabin
    if n < 4: return n == 2 or n == 3
    if n % 2 == 0: return False
    r, s = 0, n - 1
    while s % 2 == 0:
        r += 1
        s //= 2
    for _ in range(k):
        a = random.randrange(2, n - 1)
        x = pow(a, s, n)
        if x == 1 or x == n - 1: continue
        for _ in range(r - 1):
            x = pow(x, 2, n)
            if x == n - 1: break
        else:
            return False
    return True

n = int(input()) - 3

N = 1000001
isp = [True] * N
isp[:2] = [False, False]
for i in range(2, N):
    if not isp[i]: continue
    if ispp(n - i):
        print(3, i, n - i)
        exit()
    for j in range(i * 2, N, i):
        isp[j] = False
