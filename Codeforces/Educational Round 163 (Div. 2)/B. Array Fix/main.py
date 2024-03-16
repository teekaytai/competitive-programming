from itertools import chain
import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    *a, = input().split()
    m = 0
    for i in range(n-1, 0, -1):
        if int(a[i]) < int(a[i-1]):
            m = i
            break
    prev = None
    for x in chain(*a[:m]):
        if prev and x < prev:
            print('NO')
            return
        prev = x
    print('YES' if m==0 or int(prev) <= int(a[m]) else 'NO')

tcs = int(input())
for tc in range(tcs):
    main()
