import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    a, b = map(int, input().split())
    c, d = map(int, input().split())
    print(['NO', 'YES'][(a>b)==(c>d) and a!=b and c!=d])

tcs = int(input())
for tc in range(tcs):
    main()
