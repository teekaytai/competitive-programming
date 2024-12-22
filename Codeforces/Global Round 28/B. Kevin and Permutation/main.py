import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n,k = map(int, input().split())
    a = [-1] * n
    i = 1
    for j in range(k-1,n,k):
        a[j] = i
        i += 1
    for j in range(n):
        if a[j] == -1:
            a[j] = i
            i += 1
    print(*a)

tcs = int(input())
for tc in range(tcs):
    main()
