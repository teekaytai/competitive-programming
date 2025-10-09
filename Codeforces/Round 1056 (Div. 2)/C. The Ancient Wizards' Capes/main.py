import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

MOD = 676767677

R = True
L = False

def main():
    n = int(input())
    *a, = map(int, input().split())
    k = -1
    for i in range(n - 1):
        d = abs(a[i] - a[i + 1])
        if d > 1:
            print(0)
            return
        if d == 1:
            k = i
    if k == -1:
        print(1 + n % 2 if a[0] == 1 + n // 2 or a[0] == 1 + (n - 1) // 2 else 0)
        return
    bs = [R] * n
    bs[k] = R if a[k] > a[k + 1] else L
    bs[k + 1] = bs[k]
    for i in range(k + 2, n):
        bs[i] = not bs[i - 1]
    for i in range(k - 1, -1, -1):
        if a[i] == a[i + 1]:
            bs[i] = not bs[i + 1]
        elif a[i] > a[i + 1] and bs[i + 1] == L or a[i] < a[i + 1] and bs[i + 1] == R:
            print(0)
            return
        elif a[i] > a[i + 1]:
            bs[i] = R
        else:
            bs[i] = L
    s = sum(bs[i] == R for i in range(1, n))
    print(int(s + 1 == a[0]))

tcs = int(input())
for tc in range(tcs):
    main()
