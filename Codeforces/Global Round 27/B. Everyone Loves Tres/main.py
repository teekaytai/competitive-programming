import sys
from itertools import product
input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)


def main():
    n = int(input())
    # print(min((x for x in map(int,map(''.join,product('36', repeat=n))) if x%66==0), default=-1))
    print([-1,-1,66,-1][n] if n < 4 else '3'*(n-4)+'6366' if n%2 else '3'*(n-2)+'66')

tcs = int(input())
for tc in range(tcs):
    main()
