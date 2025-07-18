import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    *a, = map(int, input().split())
    for i in range(n - 1):
        if a[i] > a[i + 1]:
            print(f'YES\n2\n{a[i]} {a[i+1]}')
            return
    print('NO')

tcs = int(input())
for tc in range(tcs):
    main()
