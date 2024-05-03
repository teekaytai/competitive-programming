s,a,b = map(int, input().split())
x = (s+a-1)//a
y = 0
t = x*a
while t != s:
    if t > s:
        if x == 0: print('Impossible'); break
        x -= 1; t -= a
    else: y += 1; t += b
else:
    print(x, y)
