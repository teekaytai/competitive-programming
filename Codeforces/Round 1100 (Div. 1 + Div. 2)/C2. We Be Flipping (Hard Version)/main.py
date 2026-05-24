import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    tas = sum(map(abs, a))
    sas = 0
    ss = 0
    mx = sum(a), -1
    for i in range(n - 1, -1, -1):
        if a[i] > 0:
            mx = max(mx, (tas - sas - 2 * a[i] + ss, i))
        sas += abs(a[i])
        ss += a[i]
    if mx[1] == -1:
        print(0)
        print()
        return
    b = 1
    ans = []
    for i in range(mx[1] - 1, -1, -1):
        if b * a[i] < 0:
            continue
        ans.append(i + 1)
        b = -b
    ans.append(mx[1] + 1)
    print(len(ans))
    print(*ans)

tcs = int(input())
for tc in range(tcs):
    main()
