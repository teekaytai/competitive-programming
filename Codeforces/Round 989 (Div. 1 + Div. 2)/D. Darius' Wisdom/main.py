from collections import deque
import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    *a, = map(int, input().split())
    x = []
    q = deque()
    l = m = 0
    r = n-1
    while l<n and a[l] != 1:l+=1
    while m<n and a[m] != 2:m+=1
    while r>m:
        if a[r]==0:
            if q:
                i = q.popleft()
                a[i],a[r]=a[r],a[i]
                x.append((i,r))
            else:
                a[l],a[r]=a[r],a[l]
                x.append((l,r))
                while l<n and a[l] != 1:l+=1
        if a[r] == 1:
            a[m],a[r]=a[r],a[m]
            x.append((m,r))
            if m < l:q.append(m)
            while m<r and a[m] != 2:m+=1
        r-=1
    # printerr(a)
    l = 0
    r = m - 1
    while l < r:
        while l<r and a[l]!=1:l+=1
        while l<r and a[r]!=0:r-=1
        if a[l]!=a[r]:
            a[l],a[r]=a[r],a[l]
            x.append((l,r))
            l+=1
            r-=1
    # printerr(a)
    print(len(x))
    for i,j in x:
        print(i+1,j+1)

tcs = int(input())
for tc in range(tcs):
    main()
