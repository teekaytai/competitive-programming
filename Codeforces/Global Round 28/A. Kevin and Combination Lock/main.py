import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    print(['NO','YES'][n%33==0])

tcs = int(input())
for tc in range(tcs):
    main()
