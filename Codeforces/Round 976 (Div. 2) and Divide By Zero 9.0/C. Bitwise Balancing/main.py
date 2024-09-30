import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

B = [1, 0, 0, -1]

def main():
    b, c, d = map(int, input().split())
    d -= b
    p = [B[2*(b & (1 << i) > 0) + (c & (1<<i)>0)] for i in range(64)]
    a = 0
    for i in range(64):
        if abs(d) & 1:
            if p[i] == 0:
                print(-1)
                return
            a |= 1 << i
            d -= p[i]
        d //= 2
    print(a if d==0 else -1)

tcs = int(input())
for tc in range(tcs):
    main()
