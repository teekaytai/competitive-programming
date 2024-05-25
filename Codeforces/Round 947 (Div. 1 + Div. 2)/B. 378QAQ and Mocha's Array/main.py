import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    p, *a = sorted(map(int, input().split()))
    q = -1
    for x in a:
        if x % p == 0: continue
        if q == -1: q = x
        elif x % q != 0: print('NO'); break
    else:
        print('YES')

tcs = int(input())
for tc in range(tcs):
    main()
