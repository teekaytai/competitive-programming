import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

MOD = 998244353

def main():
    n, k = map(int, input().split())
    a = [0, *map(int, input().split())]
    l = 1
    while l <= n:
        for i in range(l, n+1, 2*l):
            j = i + (i & -i)
            d = 1
            c = k
            while j <= n:
                a[j] = (a[j] - c * a[i]) % MOD
                j += j & -j
                d += 1
                c = c * (k + d - 1) // d
        l *= 2
    print(*a[1:])

tcs = int(input())
for tc in range(tcs):
    main()
