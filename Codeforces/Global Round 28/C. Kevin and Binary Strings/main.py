import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    s = input()
    n = len(s)
    x = s.find('0')
    if x == -1:print(1,n,1,1); return
    mx = (0, 0)
    for i in range(x):
        j = 0
        while x+j < n and s[i+j] != s[x+j]: j+=1
        mx = max(mx, (j, i))
    print(1,n,mx[1]+1,mx[1]+n-x)

tcs = int(input())
for tc in range(tcs):
    main()
