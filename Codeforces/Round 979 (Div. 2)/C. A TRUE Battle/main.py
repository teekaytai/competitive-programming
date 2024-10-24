import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    s = input()
    print(['NO','YES'][s[0]=='1'or s[-1]=='1' or '11'in s])

tcs = int(input())
for tc in range(tcs):
    main()
