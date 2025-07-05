from collections import deque
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    h, w, k = map(int, input().split())
    def f(r, c):
        for dr, dc in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
            r2 = r + dr
            c2 = c + dc
            if 0 <= r2 < h and 0 <= c2 < w:
                yield r2, c2
    gs = [[0] * w for _ in range(h)]
    q = deque()
    for _ in range(k):
        r, c = map(int, input().split())
        r -= 1
        c -= 1
        gs[r][c] = 4
        q.append((r, c))
    t = 0
    i = 0
    while q:
        i += 1
        for _ in range(len(q)):
            r, c = q.popleft()
            for r2, c2 in f(r, c):
                gs[r2][c2] += 1
                if gs[r2][c2] == 2:
                    t += i
                    q.append((r2, c2))
    print(t)

main()
