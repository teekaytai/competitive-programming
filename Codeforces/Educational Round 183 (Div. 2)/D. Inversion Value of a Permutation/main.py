from functools import cache
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

@cache
def f(n, k, c):
    if k < 0 or c > k or c >= n:
        return None
    if c == 0:
        return list(range(1, n + 1)) if k == 0 else None
    if k == n * (n - 1) // 2:
        return list(range(n, 0, -1)) if c == n - 1 else None
    if n == 1:
        return None
    a = f(n - 1, k - c, c)
    if a:
        return a + [n]
    if c == n - 1:
        a = next((f(n - 1, k - c, d) for d in range(n - 1) if f(n - 1, k - c, d)), default=None)
        if a:
            b = [x + 1 for x in a]
            b.append(1)
            return b

def main():
    n, k = map(int, input().split())
    a = next((f(n, k, c) for c in range(n) if f(n, k, c)), default=None)
    if a:
        print(*a)
    else:
        print(0)

tcs = int(input())
for tc in range(tcs):
    main()
