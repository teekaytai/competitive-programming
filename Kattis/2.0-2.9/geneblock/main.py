_, *a = map(int, open(0))
for x in a:
    i = 1
    x -= 7
    while x%10: x -= 7; i += 1
    print(i if x>=0 else -1)
