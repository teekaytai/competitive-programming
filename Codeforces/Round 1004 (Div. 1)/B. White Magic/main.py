import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    *a, = map(int, input().split())
    cs = [0] * (n + 1)
    I = [1e9] * (n + 1)
    for i, x in enumerate(a):
        if x <= n:
            I[x] = min(I[x], i)
            cs[x] += 1
    mx = n - cs[0]
    if cs[0]:
        p = I[0]
        for i in range(1, n):
            if I[i] < p and cs[i] > 1:
                break
            if cs[i] == 0:
                mx += 1
                break
            p = min(p, I[i])
        else:
            mx += 1
    print(mx)

tcs = int(input())
for tc in range(tcs):
    main()
