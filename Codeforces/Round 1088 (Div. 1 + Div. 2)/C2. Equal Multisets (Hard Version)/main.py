from collections import Counter
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, m = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    b = [int(x) for x in input().split()]
    for i in range(m):
        asame = all(a[j] == a[i] for j in range(i, n, m))
        if not asame:
            for j in range(i, n, m):
                if b[j] != -1 and b[j] != a[j]:
                    print('NO')
                    return
            b[i] = a[i]
        else:
            x = -1
            for j in range(i, n, m):
                if b[j] == -1:
                    continue
                if x != -1 and b[j] != x:
                    print('NO')
                    return
                x = b[j]
            b[i] = x
    a2 = Counter(sorted(a[:m]))
    b2 = Counter(sorted(x for x in b[:m] if x != -1))
    print('YES' if b2 <= a2 else 'NO')

tcs = int(input())
for tc in range(tcs):
    main()
