import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    ps = [0] * (max(a) + 1)
    ps[0] = n
    for x in a:
        ps[x] -= 1
    for i in range(len(ps) -1 ):
        ps[i + 1] += ps[i]
    c = 0
    for i in range(len(ps)):
        c, ps[i] = divmod(ps[i] + c, 10)
    while c:
        ps.append(c % 10)
        c //= 10
    while ps and ps[-1] == 0:
        ps.pop()
    ps.reverse()
    print(''.join(map(str, ps)))

main()
