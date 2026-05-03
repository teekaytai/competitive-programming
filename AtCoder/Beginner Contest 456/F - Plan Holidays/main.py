from itertools import accumulate
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

INF = int(1e18)
I = 0, INF, INF, 0

def f(t1, t2):
    a1, b1, c1, d1 = t1
    a2, b2, c2, d2 = t2
    return min(a1 + a2, c1 + b2), min(b1 + a2, d1 + b2), min(a1 + c2, c1 + d2), min(b1 + c2, d1 + d2)

def g(x):
    return INF, 0, x, x

def h(y, p):
    return y + p[3]

class Q:
    def __init__(self):
        self.back_prod = I
        self.back_vals = []
        self.front_vals = []

    def append(self, t):
        self.back_vals.append(t)
        self.back_prod = f(self.back_prod, t)

    def pop(self):
        if not self.front_vals:
            self.front_vals += accumulate(reversed(self.back_vals), lambda t2, t1: f(t1, t2))
            self.back_vals = []
            self.back_prod = I
        self.front_vals.pop()

    def all_prod(self):
        if not self.front_vals:
            return self.back_prod
        if not self.back_vals:
            return self.front_vals[-1]
        return f(self.front_vals[-1], self.back_prod)

def main():
    n, k = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    q = Q()
    for i in range(1, k):
        q.append(g(a[i]))
    ans = h(a[0], q.all_prod())
    for i in range(k, n):
        q.append(g(a[i]))
        ans = min(ans, h(a[i - k], q.all_prod()))
        q.pop()
        ans = min(ans, h(a[i - k + 1], q.all_prod()))
    print(ans)

tcs = int(input())
for tc in range(tcs):
    main()
