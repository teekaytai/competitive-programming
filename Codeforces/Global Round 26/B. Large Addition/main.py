import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = input()
    print('YES' if n.startswith('1') and len(n)>1 and int(n[-1])<9 and all(0<int(n[i])for i in range(1, len(n)-1)) else 'NO')

tcs = int(input())
for tc in range(tcs):
    main()
