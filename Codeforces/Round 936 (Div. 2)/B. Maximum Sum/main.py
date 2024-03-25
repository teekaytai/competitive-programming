import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)
MOD = 1000000007
def main():
    n, k = map(int, input().split())
    *a, = map(int, input().split())
    t = sum(a)
    mx = 0
    s = 0
    for x in a:
        s = max(s + x, x)
        mx = max(mx, s)
    print((t - mx + mx * pow(2,k, MOD)) % MOD)

tcs = int(input())
for tc in range(tcs):
    main()
