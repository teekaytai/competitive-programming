import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, x, k = map(int, input().split())
    a = input()
    for i in range(n):
        x += 1 if a[i] == 'R' else -1
        if x == 0: break
    else:
        print(0)
        return
    k -= i + 1
    for i in range(n):
        x += 1 if a[i] == 'R' else -1
        if x == 0: break
    else:
        print(1)
        return
    print(1 + k//(i+1))

tcs = int(input())
for tc in range(tcs):
    main()
