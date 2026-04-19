import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

MOD = 1000003233
def modpow(b, p, mod=MOD):
    r = 1
    while p:
        if p & 1:
            r = (r * b) % mod
        b = (b * b) % mod
        p >>= 1
    return r

def main():
    n = int(input())
    dp1 = [0] * (n + 1)
    dp2 = [0] * (n + 1)
    dp1[0] = 1
    ms = [modpow(2, i) for i in range(n + 1)]
    for i in range(n):
        dp2[0] = dp1[0] * ms[n] % MOD
        s = dp1[0]
        for j in range(1, n + 1):
            dp2[j] = ms[n-j] * (s * ms[j - 1] % MOD + dp1[j] * ms[j] % MOD) % MOD
            s = (s + dp1[j]) % MOD
        dp1, dp2 = dp2, dp1
    t = 0
    for x in dp1: t = (t + x) % MOD
    print(t)

# tcs = int(input())
# for tc in range(tcs):
main()
