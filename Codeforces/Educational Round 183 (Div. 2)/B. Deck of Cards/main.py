import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, k = map(int, input().split())
    s = input()
    if len(s) == n:
        print('-' * n)
        return
    a = ['+'] * n
    x = s.count('0')
    y = s.count('1')
    z = s.count('2')
    a[:x] = ['-'] * x
    if y: a[-y:] = ['-'] * y
    a[x:x+z] = ['?'] * z
    a[n-y-z:n-y] = ['?'] * z
    print(''.join(a))

tcs = int(input())
for tc in range(tcs):
    main()
