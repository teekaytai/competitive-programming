from itertools import accumulate
input()
*a, = accumulate(sorted(map(int, input().split())))
for x in map(int, input().split()):
    print(a[x-1])
