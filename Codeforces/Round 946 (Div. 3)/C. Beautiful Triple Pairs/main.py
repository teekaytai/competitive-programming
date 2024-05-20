from collections import Counter
import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    *a, = map(int, input().split())
    def f(A):
        A.sort()
        X = 0
        Y = 0
        c = Counter()
        t = 0
        for x, y, z in A:
            if x != X or y != Y:
                s = sum(c.values())
                t += sum((s-v)*v for v in c.values())
                X = x
                Y = y
                c.clear()
                c[z] = 1
            else:
                c[z] += 1
        s = sum(c.values())
        t += sum((s-v)*v for v in c.values())
        return t//2
    print(f([(a[i], a[i+1], a[i+2]) for i in range(n-2)])+f([(a[i], a[i+2], a[i+1]) for i in range(n-2)])+f([(a[i+1], a[i+2], a[i]) for i in range(n-2)]))
    # x = []
    # y = []
    # z = []
    # for i in range(n-2):
    #     x.append(a[i] * 1000000 + a[i+1])
    #     y.append(a[i+1] * 1000000 + a[i+2])
    #     z.append(a[i] * 1000000 + a[i+2])
    # x.sort(); y.sort(); z.sort()
    # print(sum(Counter(r).values() for r in (x, y, z)))

tcs = int(input())
for tc in range(tcs):
    main()
