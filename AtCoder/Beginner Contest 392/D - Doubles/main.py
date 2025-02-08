from collections import Counter
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    cs = [Counter(input().split()[1:]) for _ in range(n)]
    print(max(sum(c[x] * v for x, v in cs[j].items())/(c.total() * cs[j].total()) for i, c in enumerate(cs) for j in range(i)))

# tcs = int(input())
# for tc in range(tcs):
main()
