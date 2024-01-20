import sys

input = lambda: sys.stdin.readline().strip()

tcs = int(input())
for tc in range(tcs):
    n = int(input())
    n-=1
    i = 200
    a = []
    while n:
        if n % 2:
            a.append(i)
            i-=1
            n//=2
        else:
            a.append(0)
            n-=1
    print(len(a))
    print(*reversed(a))
