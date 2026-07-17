import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, k = [int(x) for x in input().split()]
    k ^= n
    b = 1 << (k.bit_length() - 1) if k else 0
    if b >= n:
        print('NO')
        return
    p = 1
    ans = []
    p2s = [0]
    for i in range(1, n):
        if i != p:
            ans.append(i)
        else:
            if k & p:
                p2s.append(p)
            else:
                ans.append(p)
            p *= 2
    ans += p2s
    print('YES')
    print(*ans)

tcs = int(input())
for tc in range(tcs):
    main()
