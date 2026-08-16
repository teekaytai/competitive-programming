import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    a = [i for i, x in enumerate(input()) if x == '1']
    b = [i for i, x in enumerate(input()) if x == '1']
    c = [i for i, x in enumerate(input()) if x == '1']
    ans = ['0'] * (2 * n)
    t = 0
    for x, y, z in zip(a, b, c):
        x, y, z = sorted((x, y, z))
        ans[y] = '1'
        t += z - y + y - x
    assert ans.count('1') == n
    print(t)
    print(''.join(ans))

main()
