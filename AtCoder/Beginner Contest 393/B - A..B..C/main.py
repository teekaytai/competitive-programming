import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    s = input()
    n = len(s)
    t = 0
    for i in range(n):
        for l in range(1, (n - i - 1) // 2 + 1):
            t += s[i]=='A' and s[i+l]=='B' and s[i+2*l]=='C'
    print(t)

# tcs = int(input())
# for tc in range(tcs):
main()
