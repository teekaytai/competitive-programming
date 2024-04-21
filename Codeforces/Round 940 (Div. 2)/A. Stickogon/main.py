from collections import Counter
import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    *a, = sorted(map(int, input().split()))
    c = Counter(a)
    print(sum(x//3 for x in c.values()))

tcs = int(input())
for tc in range(tcs):
    main()
