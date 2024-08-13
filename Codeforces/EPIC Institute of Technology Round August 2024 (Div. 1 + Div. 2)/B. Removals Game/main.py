import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    *a, = map(int, input().split())
    *b, = map(int, input().split())
    if a[0] not in (b[0], b[-1]) or a[-1] not in (b[0], b[-1]):
        print('Alice')
        return
    if a[-1] != b[-1]:
        b = b[::-1]
    print('Bob' if a==b else 'Alice')

tcs = int(input())
for tc in range(tcs):
    main()
