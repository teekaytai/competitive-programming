import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    a = [[*input()], [*input()]]
    for i in range(n):
        a[i%2][i] = 0
    a[0][0] = 1
    for i in range(n-1):
        if not a[i%2][i]: continue
        if a[1-i%2][i] == '>': a[1-i%2][i+1] = 1
        if a[i%2][i+1] == '>': a[i%2][i+2] = 1
    print('YES' if a[1][n-1] else 'NO')

tcs = int(input())
for tc in range(tcs):
    main()
