import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n, k = map(int, input().split())
    for mx in range(n, 0, -1):
        print('?', 1, mx*n, flush=True)
        if int(input()) == n: break
    ans = -1
    for i in range(n//k, 0, -1):
        m = mx * i
        c = 1
        for j in range(1, k+1):
            print('?', c, m, flush=True)
            r = int(input())
            if r + k - j > n: break
            c = r + 1
        else:
            if c == n + 1:
                ans = m
                break
    print('!', ans, flush=True)
    assert int(input()) == 1

tcs = int(input())
for tc in range(tcs):
    main()
