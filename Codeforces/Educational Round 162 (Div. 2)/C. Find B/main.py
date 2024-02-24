from itertools import accumulate
import sys

input = lambda: sys.stdin.readline().strip()

def main():
    tcs = int(input())
    for tc in range(tcs):
        n, q = map(int, input().split())
        *a, = map(int, input().split())
        *p, = accumulate(a, lambda t, x: t+(x-1), initial=0)
        *P, = accumulate(a, lambda t, x: t+(x==1), initial=0)
        for _ in range(q):
            l, r = map(int, input().split())
            print('YES' if r>l and p[r]-p[l-1]>=P[r]-P[l-1] else 'NO')

main()
