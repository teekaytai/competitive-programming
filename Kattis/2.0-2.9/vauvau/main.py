a, b, c, d = map(int, input().split())
for x in map(int, input().split()):
    print(['none', 'one', 'both'][((x-1)%(a+b)<a)+((x-1)%(c+d)<c)])
