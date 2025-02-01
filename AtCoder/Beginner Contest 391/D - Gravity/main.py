from collections import deque
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, m = map(int, input().split())
    cs = [deque() for _ in range(m)]
    v = 0
    a = []
    ts = [2e9] * n
    for i in range(n):
        x, y = map(int, input().split())
        x -= 1
        a.append((y, x, i))
    a.sort()
    for y, x, i in a:
        cs[x].append(i)
        v += len(cs[x]) == 1
        if v == m:
            v = 0
            for i in range(m):
                ts[cs[i].popleft()] = y
                v += len(cs[i]) >= 1
    for _ in range(int(input())):
        t, a = map(int, input().split())
        print(['No', 'Yes'][ts[a-1] > t])

main()
