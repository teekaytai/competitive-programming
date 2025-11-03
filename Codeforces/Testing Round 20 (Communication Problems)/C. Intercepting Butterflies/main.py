from itertools import combinations
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

a = [sum(1 << i for i in c) for k in range(2, 6) for c in combinations(range(5), k)]

def f(x):
    ans = []
    m = 0
    for i in range(15):
        if x & 1:
            m ^= a[i]
            ans.append(i + 1)
        x >>= 1
    for i in range(5):
        if m & 1:
            ans.append(i + 16)
        m >>= 1
    return ans

def c(a, b):
    return len({*a} ^ {*b})

def main(first):
    if first:
        x = int(input()) - 1
        ans = f(x)
        print(len(ans))
        print(*ans)
    else:
        n = int(input())
        *vs, = map(int, input().split())
        x = sum(1 << (b - 1) for b in vs if b <= 15)
        if c(vs, f(x)) <= 1:
            print(x + 1)
            return
        for i in range(15):
            b = 1 << i
            y = x ^ b
            if c(vs, f(y)) <= 1:
                print(y + 1)
                break

first = input() == 'first'
tcs = int(input())
for tc in range(tcs):
    main(first)
