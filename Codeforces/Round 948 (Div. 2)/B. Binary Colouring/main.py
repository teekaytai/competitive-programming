import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    *a, = map(int, bin(n)[2:][::-1])
    a.extend([0, 0, 0])
    for i in range(len(a)):
        while a[i] > 1:
            a[i] -= 2
            a[i+1] += 1
        if a[i] and a[i+1]:
            a[i+2] += 1
            a[i] = -1
            a[i+1] -= 1
    while a[-1] == 0: a.pop()
    print(len(a))
    print(*a)

tcs = int(input())
for tc in range(tcs):
    main()
