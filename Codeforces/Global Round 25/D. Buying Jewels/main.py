import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n, k = map(int, input().split())
    if n == k: print('YES\n1\n1')
    elif (n-k+1)*2 > n:
        print('YES\n2')
        print(n-k+1, 1)
    else: print('NO')

tcs = int(input())
for tc in range(tcs):
    main()
