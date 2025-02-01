import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    g = [list(map(int, input()))]
    for _ in range(n):
        r = g[-1]
        g.append([r[i] if r[i] == r[i+1] or r[i] == r[i+2] else r[i+1] for i in range(0, len(r), 3)])
    def f(i, j):
        r = g[i]
        if i == 0: return 1 + int(r[j] == r[j+1] == r[j+2])
        a = [f(i - 1, (j + k) * 3) for k in range(3)]
        if r[j] == r[j+1] == r[j+2]: return sum(sorted(a)[:2])
        if r[j] == r[j+1]: return min(a[0], a[1])
        if r[j] == r[j+2]: return min(a[0], a[2])
        return min(a[1], a[2])
    print(f(n-1, 0))

main()
