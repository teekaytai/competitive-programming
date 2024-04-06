import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n, k = map(int, input().split())
    k -= 1
    *a, = map(int, input().split())
    x = a[k]
    if max(a) == x:
        print(n - 1)
        return
    i = 0
    while i < n and a[i] <= x: i += 1
    mx = i - 1
    if i > k: print(mx); return
    a[i], a[k] = a[k], a[i]
    t = int(i > 0)
    i += 1
    while i < n and a[i] < x: i += 1; t += 1
    print(max(mx, t))

tcs = int(input())
for tc in range(tcs):
    main()
