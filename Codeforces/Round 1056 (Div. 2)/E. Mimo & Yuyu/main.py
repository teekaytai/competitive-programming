import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

cs = [0] * 200001

def main():
    n, m, k = map(int, input().split())
    if n == 1:
        t = 0
        for _ in range(k):
            _, y = map(int, input().split())
            t += y == 2
        print(['Mimo', 'Yuyu'][1 - t % 2])
        return
    t = 0
    a = []
    for _ in range(k):
        _, y = map(int, input().split())
        if y == 1: continue
        cs[y] += 1
        t += 1 if cs[y] % 2 else -1
        a.append(y)
    print(['Mimo', 'Yuyu'][t == 0])

    for y in a:
        cs[y] = 0

tcs = int(input())
for tc in range(tcs):
    main()
