import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    *a, = map(int, input().split())
    print('YES' if sum(y<x for x,y in zip(a, a[1:]))+(a[0]<a[-1])<2 else 'NO')

tcs = int(input())
for tc in range(tcs):
    main()
