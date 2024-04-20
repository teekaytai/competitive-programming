for _ in range(int(input())):
    x,y=map(int,input().split())
    print(x, y*(y+1)//2+y)
