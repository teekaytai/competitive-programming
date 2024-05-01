t = 0
for _ in range(int(input())):
    g,b = map(int, input().split())
    t += g
    if t < b:
        print('impossible')
        break
else:
    print('possible')
