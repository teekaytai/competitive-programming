K = []
L = []
while True:
    k, l = map(int, input().split())
    if not k: break
    K.append(k)
    L.append(l)
N = max(L)
X = [True] * N
P = []
for i in range(2, N):
    if X[i]:
        for j in range(i+i, N, i):
            X[j] = False
        P.append(i)
for k, l in zip(K, L):
    c = 0
    for p in P:
        if p >= l:
            break
        if k % p == 0:
            c = p
            break
    print('BAD', c) if c else print('GOOD')
