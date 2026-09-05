import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    ans = ['A', 'R'] * 50
    t = 0
    for i in range(49, -1, -1):
        if n == 0:
            break
        if i - t <= n:
            n -= i - t
            ans[2 * i] = 'C'
            t += 1
    assert n == 0
    print(''.join(ans))

main()
