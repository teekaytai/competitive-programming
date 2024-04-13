import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    s1 = input()
    s2 = input()
    a1 = []
    a2 = []
    b = False
    for d1, d2 in zip(s1, s2):
        if not b:
            if d1 == d2: a1.append(d1); a2.append(d2)
            else:
                b = True
                a1.append(max(d1, d2))
                a2.append(min(d1, d2))
        else:
            a1.append(min(d1, d2))
            a2.append(max(d1, d2))
    print(''.join(a1))
    print(''.join(a2))

tcs = int(input())
for tc in range(tcs):
    main()
