import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    s = input()
    a = [i for i in range(n) if s[i] == '1']
    m = len(a) // 2
    t = 0
    for i in range(len(a)):
        t += abs(a[m] - m + i - a[i])
    print(t)

# tcs = int(input())
# for tc in range(tcs):
main()
