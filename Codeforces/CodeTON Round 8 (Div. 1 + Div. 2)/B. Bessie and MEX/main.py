import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    *a, = map(int, input().split())
    p = []
    used = [False] * n
    c = 0
    c2 = 1
    for x in a:
        if x == c2 - c:
            p.append(c)
            used[c] = True
            c = c2
            c2 += 1
        else:
            p.append(c - x)
            used[c - x] = True
        while c2 < n and used[c2]:
            c2 += 1
    print(*p)

tcs = int(input())
for tc in range(tcs):
    main()
