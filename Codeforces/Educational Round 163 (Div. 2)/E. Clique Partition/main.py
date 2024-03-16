import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n, k = map(int, input().split())
    l = 1
    i = 1
    a = []
    c = []
    while i <= n:
        s = min(i+k-1, n)
        m = (i+s)//2
        a.extend([*range(m, i-1, -1), *range(s, m, -1)])
        c += [l] * (s-i+1)
        l += 1
        i += k
    print(*a)
    print(c[-1])
    print(*c)


tcs = int(input())
for tc in range(tcs):
    main()
