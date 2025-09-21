from collections import Counter
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    *a, = map(int, input().split())
    c = Counter(a)
    b = sorted(list(c.values()))
    ans = 0
    for i, x in enumerate(b):
        ans = max(ans, (len(b) - i) * x)
    print(ans)

tcs = int(input())
for tc in range(tcs):
    main()
