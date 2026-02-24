from itertools import chain
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, k = [int(x) for x in input().split()]
    if n == 1:
        if k == 1:
            print('YES\n1 1')
        else:
            print('NO')
        return
    if n == 2:
        if k == 2:
            print('YES\n1 1 2 2')
        elif k == 3:
            print('YES\n1 2 1 2')
        else:
            print('NO')
        return
    if k < n or k > n + n - 1:
        print('NO')
        return
    print('YES')
    if k == n:
        print(*chain(*zip(range(1, n + 1), range(1, n + 1))))
        return
    k -= n + 1
    a = [1, 2]
    for i in range(1, k + 1):
        a.append(i + 2)
        a.append(i)
    a.append(k + 1)
    a.append(k + 2)
    r = range(k + 3, n + 1)
    a += chain(*zip(r, r))
    print(*a)

tcs = int(input())
for tc in range(tcs):
    main()
