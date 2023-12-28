tcs = int(input())
for tc in range(tcs):
    n = int(input())
    a = [*map(int, input().split())]
    if any(x==0 for x in a) or sum(x<0 for x in a)%2==1:
        print(0)
    else:
        print(1)
        print(1, 0)
