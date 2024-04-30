from math import gcd

N = 10000
X = [True] * N
P = []
for i in range(2, N):
    if X[i]:
        for j in range(i+i, N, i):
            X[j] = False
        P.append(i)

def f(n):
    for p in 2, 3, 5, 7:
        if p >= n:
            return True
        if gcd(p, n) != 1 or pow(p, n-1, n) != 1:
            return False
    return True

tcs = int(input())
for tc in range(tcs):
    n = int(input())
    if n % 2: print(2 if f(n+2) else -1); continue
    for p in P:
        if f(n + p):
            print(p)
            break
    else:
        assert False
