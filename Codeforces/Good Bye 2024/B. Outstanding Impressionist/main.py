import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    a = [tuple(map(int, input().split())) for _ in range(n)]
    cs = [0] * (2 * n + 1)
    ps = [0] * (2 * n + 1)
    for l, r in a:
        if l == r: cs[l] += 1
    # printerr(cs)
    for i in range(2 * n):
        ps[i + 1] = ps[i] + (cs[i + 1] > 0)
    # printerr(ps)
    x = [int(ps[r] - ps[l - 1] != r - l + 1 if l != r else cs[l] == 1) for l, r in a]
    print(*x, sep='')

tcs = int(input())
for tc in range(tcs):
    main()
