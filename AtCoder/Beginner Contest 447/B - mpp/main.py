from collections import Counter
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    s = input()
    c = Counter(s)
    mx = max(c.values())
    m = set(k for k, v in c.items() if v == mx)
    print(''.join(x for x in s if x not in m))

main()
