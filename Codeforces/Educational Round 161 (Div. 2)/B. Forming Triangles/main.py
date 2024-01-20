from collections import Counter
import sys

input = lambda: sys.stdin.readline().strip()

tcs = int(input())
for tc in range(tcs):
    n = int(input())
    *a, = map(int, input().split())
    c = Counter(a)
    vs = sorted(c.items())
    t = 0
    s = 0
    for i, (k, v) in enumerate(vs):
        t += v * (v-1) * (v-2) // 6 + v * (v-1) // 2 * s
        s += v
    print(t)
