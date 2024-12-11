from math import factorial
from itertools import permutations
import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n, k = map(int, input().split())
    if n == k == 1:
        print('YES')
        print(1)
        return
    if k==1 or n<=9 and (k == factorial(n)-1 or k > factorial(n)) or n%2==0 and k%2==1:
        print('NO')
        return
    print('YES')
    P = permutations(range(1, n+1))
    if k%2==0:
        for _ in range(k//2):
            p = next(P)
            print(*p)
            print(*(n-x+1 for x in p))
    else:
        a = (*range((n+3)//2, n+1), *range(1, (n+3)//2))
        b = tuple(y-x for x,y in zip(a, range(3*(n+1)//2-1,3*(n+1)//2-n-1,-1)))
        print(*range(1, n+1))
        print(*a)
        print(*b)
        next(P)
        v = (k-3)//2
        while v:
            p = next(P)
            q = tuple(n-x+1 for x in p)
            if p == a or p == b or q == a or q == b: continue
            print(*p)
            print(*q)
            v -= 1

tcs = int(input())
for tc in range(tcs):
    main()
