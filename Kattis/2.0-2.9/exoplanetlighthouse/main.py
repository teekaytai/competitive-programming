import math
for _ in range(int(input())):
    r, h1, h2 = map(float, input().split())
    a = math.acos(r/(r+h1/1000)) + math.acos(r/(r+h2/1000))
    print(a * r)
