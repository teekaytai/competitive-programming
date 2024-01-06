tcs = int(input())
for tc in range(tcs):
    a,b = map(int, input().split())
    print(['Alice','Bob'][1-(a+b)%2])
