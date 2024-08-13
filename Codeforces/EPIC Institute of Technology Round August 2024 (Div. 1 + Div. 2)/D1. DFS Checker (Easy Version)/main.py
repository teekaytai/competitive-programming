import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)


def main():
    n, q = map(int, input().split())
    input()
    p = [int(x) for x in input().split()]

    P = [-1] * n

    def c(n, i):
        if n == 1:
            return -1, -1
        if i == 0:
            return 1, (n + 1) // 2
        n //= 2
        r = (i - 1) % n
        j, k = c(n, r)
        if j < 0: return j, k
        return j + i - r, k + i - r

    def f(i):
        j, k = c(n, i)
        if j >= 0:
            P[j] = i
            P[k] = i
        return j == -1 or sorted((p[j], p[k])) == [p[i]*2, p[i]*2+1]

    b = [f(i) for i in range(n)]
    t = sum(b)
    for _ in range(q):
        x, y = map(int, input().split())
        x -= 1; y -= 1
        t -= b[x] + b[y]
        p[x], p[y] = p[y], p[x]
        b[x] = f(x)
        b[y] = f(y)
        t += b[x] + b[y]
        if x > 0:
            t -= b[P[x]]
            b[P[x]] = f(P[x])
            t += b[P[x]]
        if y > 0:
            t -= b[P[y]]
            b[P[y]] = f(P[y])
            t += b[P[y]]
        print('YES' if t == n else 'NO')

tcs = int(input())
for tc in range(tcs):
    main()
