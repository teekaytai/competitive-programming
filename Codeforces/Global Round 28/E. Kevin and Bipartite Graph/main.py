import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n, m = map(int, input().split())
    n2 = 2*n
    if m >= n2: print('NO'); return
    print('YES')
    a = [[-1]*m for _ in range(n2)]
    for i in range(m):
        for j in range(n):
            k=(i+2*j)%n2
            a[k][i] = j+1
            a[(k+1)%n2][i] = j+1
    for r in a:
        print(*r)

tcs = int(input())
for tc in range(tcs):
    main()
