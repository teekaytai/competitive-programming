import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, k = map(int, input().split())
    if k == n*n - 1:
        print('NO')
        return
    print('YES')
    a = [['U' if i*n+j<k else 'R' if i == n-1 else 'D' for j in range(n)] for i in range(n)]
    a[-1][-1] = 'L'
    for r in a:
        print(''.join(r))


tcs = int(input())
for tc in range(tcs):
    main()
