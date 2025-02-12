import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    h, w = map(int, input().split())
    m = max(h, w)
    DIRS = [(-1, 0), (0, 1), (1, 0), (0, -1)]
    g = ['NESW'.index(c) for _ in range(h) for c in input()]
    S = g[0]
    R = 0
    C = 0
    r = 0
    c = 0
    while g[r*w+c] < 4:
        dr, dc = DIRS[g[r*w+c]]
        g[r*w+c] = 10000000+(R*m+C)
        r += dr
        c += dc
        if r < 0: R -= 1; r += h
        if r >= h: R += 1; r -= h
        if c < 0: C -= 1; c += w
        if c >= w: C += 1; c -= w
    if g[r*w+c] == 10000000+(R*m+C): print(0)
    else:
        dr, dc = DIRS[S]
        print(1)
        print(dr%h+1, dc%w+1, 'NESW'[(S + 2) % 4])

main()
