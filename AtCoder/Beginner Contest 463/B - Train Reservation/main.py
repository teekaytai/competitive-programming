import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, c = input().split()
    n = int(n)
    i = ord(c) - ord('A')
    ans = False
    for _ in range(n):
        s = input()
        ans |= s[i] == 'o'
    print('Yes' if ans else 'No')

main()
