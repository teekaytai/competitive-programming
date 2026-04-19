import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, a, b = [int(x) for x in input().split()]
    a -= 1
    b -= 1
    if n % 2 or (a^b)%2==0:
        print('No')
        return
    print('Yes')
    s1 = f"{'R' * (n - 1)}D{'L' * (n - 1)}D"
    s2 = f"{'L' * (n - 1)}D{'R' * (n - 1)}D"
    t = (
        f"{'DRUR' * (b // 2)}DR{'RURD' * ((n - 2 - b//2*2) // 2)}D"
        if a % 2 == 0
        else f"{'DRUR' * (b // 2)}RD{'RURD' * ((n - 2 - b//2*2) // 2)}D"
    )
    ans = [*[s1] * (a//2), t, *[s2] * ((n - a - 1) // 2)]
    ans[-1] = ans[-1][:-1]
    print(''.join(ans))

tcs = int(input())
for tc in range(tcs):
    main()
