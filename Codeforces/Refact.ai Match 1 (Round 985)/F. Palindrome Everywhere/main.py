import re
import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    s = input()
    r = s.count('R')
    b = s.count('B')
    if r<=1 or b<=1:
        print('YES')
        return
    ri = s.find('R')
    bi = s.find('B')
    bs = s[bi:] + s[:bi]
    rs = s[ri:] + s[:ri]
    rc = sum(len(m) % 2 == 0 for m in re.findall('R+', bs))
    bc = sum(len(m) % 2 == 0 for m in re.findall('B+', rs))
    print(['NO','YES']['BB' not in rs and rc==1 or 'RR' not in bs and bc==1])

tcs = int(input())
for tc in range(tcs):
    main()
