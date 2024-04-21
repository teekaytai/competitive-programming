import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

MOD = 1000000007

def main():
    n, k = map(int, input().split())
    for _ in range(k):
        x, y = map(int, input().split())
        n -= 1 + (x!=y)
    p1 = 1
    p2 = 1
    for i in range(2, n+1):
        p1, p2 = (p1 + p2*(2*i-2)) % MOD, p1
    print(p1)

tcs = int(input())
for tc in range(tcs):
    main()
