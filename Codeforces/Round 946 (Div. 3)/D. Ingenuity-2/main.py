import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)
D = 'NSEW'
def main():
    n = int(input())
    s = input()
    c = [0] * 4
    for x in s:
        c[D.find(x)] += 1
    if (c[0]+c[1])%2 or (c[2]+c[3])%2 or sorted(c) == [0,0,1,1]: print('NO')
    else:
        c = [c[0]//2, c[1]//2, (c[2]+1)//2, (c[3]+1)//2]
        a = []
        for x in s:
            i = D.find(x)
            if c[i]:
                a.append('H')
                c[i] -= 1
            else:
                a.append('R')
        print(''.join(a))

tcs = int(input())
for tc in range(tcs):
    main()
