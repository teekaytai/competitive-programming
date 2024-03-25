import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    *a, = map(int, input().split())
    a.sort()
    print(a[(n+1)//2-1:].count(a[(n+1)//2-1]))

tcs = int(input())
for tc in range(tcs):
    main()
