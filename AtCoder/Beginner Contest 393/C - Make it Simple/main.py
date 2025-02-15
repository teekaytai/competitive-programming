import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, m = map(int, input().split())
    s = set()
    t = 0
    for _ in range(m):
        u, v = sorted(map(int, input().split()))
        if u == v or (u, v) in s: t += 1
        s.add((u, v))
    print(t)

# tcs = int(input())
# for tc in range(tcs):
main()
