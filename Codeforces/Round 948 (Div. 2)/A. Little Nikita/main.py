import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    a, b = map(int, input().split())
    print('YES' if a>=b and (a-b)%2==0 else 'NO')

tcs = int(input())
for tc in range(tcs):
    main()
