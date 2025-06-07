import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    s = input()
    for i in range(n - 1):
        if s[i] > s[i + 1]:
            j = i + 1
            while j < n and s[i] >= s[j]: j += 1
            s = f"{s[:i]}{s[i+1:j]}{s[i]}{s[j:]}"
            break
    print(s)

tcs = int(input())
for tc in range(tcs):
    main()
