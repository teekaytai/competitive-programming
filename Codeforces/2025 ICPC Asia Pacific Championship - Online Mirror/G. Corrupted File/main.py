from itertools import groupby
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, m = map(int, input().split())
    s = [(k, sum(1 for _ in v)) for k, v in groupby(input())]
    t = [(k, sum(1 for _ in v)) for k, v in groupby(input())]
    if s[0][0] == '0' != t[0][0] or s[-1][0] == '0' != t[-1][0]: return False
    if s[0][0] != t[0][0]: s.pop(0)
    if not s: return False
    if s[-1][0] != t[-1][0]: s.pop()
    if not s: return False
    if s[0][0] == '1' and s[0][1] < t[0][1]: return False
    if s[-1][0] == '1' and s.pop()[1] < t.pop()[1]: return False
    if s and not t: return False
    i = 0
    for k, v in t:
        if k == '1':
            while i < len(s) and s[i][1] < v: i += 2
            if i >= len(s): return False
        else:
            l = 0
            while i < len(s):
                l += s[i][1]
                if l >= v: break
                i += 2
            else: return False
        i += 1
    return True

tcs = int(input())
for tc in range(tcs):
    print(['no','yes'][main()])
