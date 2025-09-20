import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    a = sorted(map(int, input().split()))
    s = sum(a)
    a.append(0)
    t = 0
    b = []
    p = a[0]
    l = 0
    for v in a:
        if v == p:
            l += 1
        else:
            if p % 2 == 1:
                b.append(l)
            t += p // 2 * l
            p = v
            l = 1
    b.sort()
    t += sum(b[-1::-2])
    print(t, s - t)

tcs = int(input())
for tc in range(tcs):
    main()
