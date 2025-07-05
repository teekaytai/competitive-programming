from collections import deque
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    q = deque()
    for _ in range(n):
        t, *a = map(int, input().split())
        if t == 1:
            q.append(tuple(a))
        else:
            s = 0
            x = a[0]
            while x:
                c, v = q.popleft()
                mn = min(x, c)
                x -= mn
                s += v * mn
                if mn < c:
                    q.appendleft((c - mn, v))
            print(s)

main()
