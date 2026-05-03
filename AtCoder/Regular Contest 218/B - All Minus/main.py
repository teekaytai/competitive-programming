from collections import Counter
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    c = Counter(a)
    x = c.pop(0, 0)
    b = sorted(c.items(), reverse=True)
    m = len(b)
    b = [b[i] if i == m - 1 else (b[i][0] - b[i+1][0], b[i][1]) for i in range(m)]
    want = False
    for k, v in b:
        want = not want or v > 1
        want = not want or k > 1
    if x == 0:
        print('Alice' if want else 'Bob')
    elif x == 1:
        print('Bob' if want else 'Alice')
    else:
        print('Alice')

tcs = int(input())
for tc in range(tcs):
    main()
