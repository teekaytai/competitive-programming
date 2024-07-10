import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n, m = map(int, input().split())
    a = [list(map(int, input()))for _ in range(n)]
    b = [list(map(int, input()))for _ in range(n)]
    print('YES' if all((sum(r2) - sum(r1))%3==0 for r1, r2 in zip(a, b)) and all((sum(r2) - sum(r1))%3==0 for r1, r2 in zip(zip(*a), zip(*b))) else 'NO')

tcs = int(input())
for tc in range(tcs):
    main()
