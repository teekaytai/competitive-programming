from itertools import accumulate
import sys

input = lambda: sys.stdin.readline().strip()

tcs = int(input())
for tc in range(tcs):
    n = int(input())
    *a, = map(int, input().split())
    direction = [a[i+1]-a[i]<a[i]-a[i-1]if 0<i<n-1 else i==0 for i in range(n)]
    right_cost = [0] * n
    # right_peaks = [0] * n
    left_cost = [0] * n
    # left_peaks = [0] * n
    # c=p = n-1
    for i in range(n-2, -1, -1):
        right_cost[i] = 1 if direction[i] else a[i+1] - a[i]
        # if direction[i]: c = i
        # else: p = i
        # right_peaks[i] = p
    # c=0
    for i in range(1, n):
        left_cost[i] = 1 if not direction[i] else a[i] - a[i-1]
        # if not direction[i]: c = i
        # else: p = i
        # left_peaks[i] = p
    rcp = [*accumulate(right_cost, initial=0)]
    lcp = [*accumulate(left_cost[::-1], initial=0)]
    lcp=lcp[::-1]
    m = int(input())
    for _ in range(m):
        x, y = map(int, input().split())
        x-=1
        y-=1
        if y > x:
            print(rcp[y] - rcp[x])
        else:
            print(lcp[y+1] - lcp[x+1])
