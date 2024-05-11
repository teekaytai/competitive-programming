import math
a, b = map(int, input().split())
if b < 181: print('safe')
else: print(math.floor(-a/math.sin(b*math.pi/180)))
