import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

MOD = 1000000007

def main():
    l, r, k = map(int, input().split())
    n = sum(d*k<10 for d in range(10))
    print((pow(n, r, MOD) - pow(n, l, MOD)) % MOD)

tcs = int(input())
for tc in range(tcs):
    main()
