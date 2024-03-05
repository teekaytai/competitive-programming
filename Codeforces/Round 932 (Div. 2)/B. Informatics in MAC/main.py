from collections import Counter
import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    *a, = map(int, input().split())
    c = Counter(sorted(a))
    for i in range(n):
        if c[i] == 1:
            print(-1)
            return
        if c[i] == 0:
            good = 0
            c2 = [0] * n
            j = 0
            while good < i:
                x = a[j]
                c2[x] += 1
                if x < i and c2[x] == 1:
                    good += 1
                if x < i and c2[x] == c[x]:
                    print(-1)
                    return
                j += 1
            # printerr(i, j, good)
            j = max(j, 1)
            print(2)
            print(1, j)
            print(j+1, n)
            return

tcs = int(input())
for tc in range(tcs):
    main()
