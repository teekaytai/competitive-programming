import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    a = input()
    b = input()
    m = 0
    for i in range(len(b)):
        j = i
        c = 0
        for x in a:
            if x == b[j]:
                j += 1
                c += 1
            if j == len(b):
                break
        m = max(m, c)
    print(len(a) + len(b) - m)

tcs = int(input())
for tc in range(tcs):
    main()
