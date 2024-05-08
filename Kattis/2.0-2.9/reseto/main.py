N, K = map(int, input().split())
N += 1
isp = [True] * N
isp[:2] = [False, False]
for i in range(2, N):
    if not isp[i]: continue
    for j in range(i, N, i):
        K -= isp[j]
        isp[j] = False
        if not K: print(j); exit()
