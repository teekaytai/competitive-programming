import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    h, w = [int(x) for x in input().split()]
    g = [input() for _ in range(2 * h)]
    s = h * w
    t = 0
    ans = [['A'] * w + ['B'] * w for _ in range(2 * h)]
    for i in range(2 * h):
        for j in range(w):
            t += g[i][j] == 'o'
    for r in range(2 * h):
        R = range(w) if r % 2 == 0 else range(w - 1, -1, -1)
        for c in R:
            if t == s:
                for row in ans:
                    print(''.join(row))
                return
            ans[2 * h - r - 1][w + c] = 'A'
            t += g[2 * h - r - 1][w + c] == 'o'
            ans[r][w - c - 1] = 'B'
            t -= g[r][w - c - 1] == 'o'
    assert False


tcs = int(input())
for tc in range(tcs):
    main()
