import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

N = 1000001
primes = []
isp = [True] * N
for i in range(2, N):
    if not isp[i]: continue
    primes.append(i)
    for j in range(i*2, N, i):
        isp[j] = False

MOD = 1000000007

ans = [0] * N
for i in range(4, N, 8):
    ans[i] = 2
for i in range(8, N, 8):
    ans[i] = -2
for p in primes:
    d = 0
    for i in range(p, N, p):
        ans[i] = (ans[i] + (p-1 if d==0 else -1)) % MOD
        d = (d + 1) % p
for i in range(1, N):
    ans[i] = (ans[i] + ans[i-1]) % MOD
for i in range(1, N):
    ans[i] = (ans[i] + ans[i-1]) % MOD

tcs = int(input())
for tc in range(tcs):
    print(ans[int(input())])
