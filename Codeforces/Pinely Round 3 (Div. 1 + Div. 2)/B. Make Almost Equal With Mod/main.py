tcs = int(input())
for tc in range(tcs):
    n = int(input())
    a =[*map(int,input().split())]
    b = 2
    while len({x%b for x in a}) != 2:
        b *= 2
    print(b)
