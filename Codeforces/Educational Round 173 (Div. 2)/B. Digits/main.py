import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n, d = map(int, input().split())
    a = [1]
    if d % 3 == 0 or n > 2: a.append(3)
    if d == 5 or d == 0: a.append(5)
    if d == 7 or n >= 3: a.append(7)
    if d % 9 == 0 or d % 3 == 0 and n > 2 or n >= 6: a.append(9)
    print(*a)

tcs = int(input())
for tc in range(tcs):
    main()
