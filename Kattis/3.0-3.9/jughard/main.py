import math
for _ in range(int(input())):
    a, b, d = map(int, input().split())
    print(['No','Yes'][d%math.gcd(a,b)==0])
