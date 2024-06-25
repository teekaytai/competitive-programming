import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    x, y, z, k = map(int, input().split())
    m = 0
    for p in range(1, x+1):
        if k%p: continue
        k2 = k // p
        for q in range(1, y+1):
            if k2%q: continue
            r = k2 // q
            m = max(m, (x-p+1)*(y-q+1)*max(z-r+1, 0))
    print(m)

tcs = int(input())
for tc in range(tcs):
    main()
