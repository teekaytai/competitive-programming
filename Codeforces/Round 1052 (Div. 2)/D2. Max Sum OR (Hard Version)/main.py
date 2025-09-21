import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    L, R = map(int, input().split())
    r = R
    l = L
    o = L
    a = list(range(l, r + 1))
    while r > l:
        p = 1 << (r.bit_length() - 1)
        if l >= p:
            l -= p
            r -= p
            o -= p
            continue
        d = min(r - p, p - 1 - l)
        x = p - d - 1
        y = p + d
        a[x-o:y+1-o] = a[x-o:y+1-o][::-1]
        if x == l:
            l = y + 1
            l -= p
            r -= p
            o -= p
        else:
            r = x - 1
    print(sum(x | y for x, y in zip(a, range(L, R + 1))))
    print(*a)

tcs = int(input())
for tc in range(tcs):
    main()
