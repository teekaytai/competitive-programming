import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    if n %2:
        print('NO')
        return
    print('YES')
    a = ['A', 'A', 'B', 'B'] * 50
    print(''.join(a[:n]))

tcs = int(input())
for tc in range(tcs):
    main()
