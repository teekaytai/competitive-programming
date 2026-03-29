from collections import Counter
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, m = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    b = [int(x) for x in input().split()]
    can = True
    can &= all(b[i] == a[i] or b[i] == -1 for i in range(n - m))
    can &= all(b[i] == a[i] or b[i] == -1 for i in range(n - (n - m), n))
    l = n - m
    r = n - (n - m)
    if l < r:
        a2 = Counter(sorted(a[l:r]))
        b2 = Counter(sorted(x for x in b[l:r] if x != -1))
        can &= b2 <= a2
    print('YES' if can else 'NO')

tcs = int(input())
for tc in range(tcs):
    main()
