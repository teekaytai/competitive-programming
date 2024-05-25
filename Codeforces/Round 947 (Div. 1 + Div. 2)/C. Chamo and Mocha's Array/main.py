import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    *a, = map(int, input().split())
    m = 0
    for i in range(n - 1):
        if a[i] < a[i+1]: m = max(m, a[i])
        else: m = max(m, a[i+1])
        if i < n - 2:
            if a[i] < a[i+2]: m = max(m, a[i])
            else: m = max(m, a[i+2])
    print(m)

tcs = int(input())
for tc in range(tcs):
    main()
