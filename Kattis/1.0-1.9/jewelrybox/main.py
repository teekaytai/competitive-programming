for _ in range(int(input())):
    x,y = map(int, input().split())
    a=12;b=-4*(x+y);c=x*y
    h=(-b-(b*b-4*a*c)**.5)/2/a
    print((x-2*h)*(y-2*h)*h)
