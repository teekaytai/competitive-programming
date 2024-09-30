import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n, k = map(int, input().split())
    if k == 1:print(n); return
    t = 0
    while n:
        t += n % k
        n //= k
    print(t)

tcs = int(input())
for tc in range(tcs):
    main()
