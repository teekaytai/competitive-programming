import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def q(u, v):
    print(u, v, flush=True)
    return int(input())

def main():
    n = int(input())
    s = [{i} for i in range(1, n + 1)]
    while True:
        s2 = []
        if len(s) % 2:
            s2.append(s.pop())
        for i in range(0, len(s), 2):
            for u in s[i]:
                for v in s[i + 1]:
                    if q(u, v):
                        return
            s[i] |= s[i + 1]
            s2.append(s[i])
        s = s2

tcs = int(input())
for tc in range(tcs):
    main()
