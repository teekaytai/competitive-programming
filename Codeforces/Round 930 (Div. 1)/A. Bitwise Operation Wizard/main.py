import sys

input = lambda: sys.stdin.readline().strip()

def query(a, b, c=None, d=None):
    if c is not None:
        print('?', a, b, c, d, flush=True)
    else:
        print('?', a, a, b, b, flush=True)
    return '<=>'.index(input()) - 1

def main():
    tcs = int(input())
    for tc in range(tcs):
        n = int(input())
        mx = 0
        for x in range(1, n):
            if query(x, mx) == 1:
                mx = x
        ms = [0 if mx else 1]
        for x in range(1, n):
            if x == mx: continue
            q = query(x, mx, ms[0], mx)
            if q == 1:
                ms = [x]
            elif q == 0:
                ms.append(x)
        mn = ms[0]
        for x in ms:
            if x == mn: continue
            if query(x, mn) == -1:
                mn = x
        print('!', mn, mx, flush=True)

main()
