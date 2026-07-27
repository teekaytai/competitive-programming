import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

MOD = 998244353

def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    try:
        l = a.index(n - 1)
    except:
        print(0)
        return
    r = l
    while r < (n - 2) and a[r + 1] == n - 1:
        r += 1
    try:
        a.index(n - 1, r + 1)
        print(0)
        return
    except:
        pass
    ans = 2
    seen = [0] * (n + 1)
    seen[n - 1] = r - l + 1
    for i in range(l):
        if i > 0:
            if a[i] == a[i - 1]:
                seen[a[i]] += 1
                continue
            if a[i] < a[i - 1]:
                print(0)
                return
        if seen[a[i]]:
            print(0)
            return
        seen[a[i]] = 1
    for i in range(r + 1, n - 1):
        if i > r + 1:
            if a[i] == a[i - 1]:
                seen[a[i]] += 1
                continue
            if a[i] > a[i - 1]:
                print(0)
                return
        if seen[a[i]]:
            print(0)
            return
        seen[a[i]] = 1
    c = 0
    for i in range(n - 1, 0, -1):
        if seen[i]:
            c += seen[i] - 1
        else:
            ans = ans * c % MOD
            c -= 1
    print(ans)

tcs = int(input())
for tc in range(tcs):
    main()
