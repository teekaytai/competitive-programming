for _ in range(int(input())):
    a,b = map(int, input().split())
    print((a+b)*(a+b+1)//2+b+1)
