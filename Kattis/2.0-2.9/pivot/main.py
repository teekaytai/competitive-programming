from itertools import accumulate
n = int(input())
*a, = map(int, input().split())
*MX, = accumulate(a, max)
*MN, = accumulate(reversed(a), min)
print(sum(MX[i] <= a[i] <= MN[-i-1] for i in range(n)))
