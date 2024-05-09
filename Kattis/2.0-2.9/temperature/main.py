x, y = map(int, input().split())
if x != 0 and y == 1: print('IMPOSSIBLE')
elif x == 0 and y == 1: print('ALL GOOD')
else: print(-x/(y-1))
