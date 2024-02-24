import sys

input = lambda: sys.stdin.readline().strip()

def main():
    tcs = int(input())
    for tc in range(tcs):
        n, k = map(int, input().split())
        *A, = map(int, input().split())
        *X, = map(abs, map(int, input().split()))
        d = 0
        c = 0
        for x, a in sorted(zip(X, A)):
            d += k * (x - c)
            c = x
            d -= a
            if d < 0: print('NO'); break
        else:
            print('YES')

main()
