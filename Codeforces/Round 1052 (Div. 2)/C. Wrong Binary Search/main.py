import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    s = input()
    a = list(range(1, n + 1))
    p = 0
    while p < n:
        l = s.find('0', p)
        if l == -1:
            break
        r = s.find('1', l + 1)
        if r == -1:
            r = n
        if l + 1 == r:
            print('NO')
            return
        a[l:r] = a[l:r][::-1]
        p = r
    print('YES')
    print(*a)

tcs = int(input())
for tc in range(tcs):
    main()
