import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    *a, = map(int, input().split())
    *b, = map(int, input().split())
    *c, = map(int, input().split())
    v = [a, b, c]
    T = (sum(a) + 2) // 3
    ans = [0] * 6
    def f(j=0, x=[False]*3):
        if all(x): return True
        for i in range(3):
            if x[i]: continue
            x[i] = True
            t = 0
            k = j
            while k < n:
                t += v[i][k]
                k += 1
                if t >= T:
                    ans[2*i] = j+1
                    ans[2*i+1] = k
                    if f(k): return True
                    break
            x[i] = False
    print(*ans) if f() else print(-1)

tcs = int(input())
for tc in range(tcs):
    main()
