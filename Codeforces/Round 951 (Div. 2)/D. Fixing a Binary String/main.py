import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n, k = map(int, input().split())
    *a, = map(int, input())
    b = [True] * n
    c = 1 - a[0]
    can = True
    for i in range(n):
        if i%k == 0: c = 1-c
        can &= a[i] == c
        b[i] = can
    # printerr(b)
    s = a[0] if n//k%2 else 1-a[0]
    first = True
    l = 0
    can = True
    for i in range(n-1, 0, -1):
        if i == n-1 or a[i] == a[i+1]:
            l += 1
            can &= l <= k
        else:
            can &= first or l == k
            first = False
            l = 1
        b[i-1] &= a[i] == s and can and (first or l==k)
    # printerr(b)
    # return next((i+1 for i in range(n) if b[i]), -1)
    print(next((i+1 for i in range(n) if b[i]), -1))

# for n in range(1, 10):
#     for k in range(1, n+1):
#         if n% k: continue
#         for x in range(1 << n):
#             *a, = map(int, f'{x:0{n}b}')
#             r = main()
#             if r>0:
#                 printerr(n, k, a)
#                 print(r, ''.join(map(str,a[r:]+a[r-1::-1])))

tcs = int(input())
for tc in range(tcs):
    main()
