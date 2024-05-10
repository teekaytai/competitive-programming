import re
import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    s = input()
    a = re.findall('0+', s)
    b = re.findall('1+', s)
    print(len(a)+len(b)-('01' in s))

tcs = int(input())
for tc in range(tcs):
    main()
