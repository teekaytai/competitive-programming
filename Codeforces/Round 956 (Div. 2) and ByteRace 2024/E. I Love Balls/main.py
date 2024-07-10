import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

MOD = 1000000007

def modinv(x, mod=MOD):
    return x and pow(x, -1, mod)

def moddiv(a, b, mod=MOD):
    return a * modinv(b, mod) % mod

def main():
    n, k = map(int, input().split())
    *a, = map(int, input().split())
    m = n - k
    q = m // 2
    p = m - q
    x = sum(a[:k])
    y = sum(a[k:])
    print((moddiv(y*p%MOD,m)+moddiv(x*(p+1-m%2)%MOD,m+1))%MOD,(moddiv(y*q%MOD,m)+moddiv(x*(q+m%2)%MOD,m+1))%MOD)

tcs = int(input())
for tc in range(tcs):
    main()
