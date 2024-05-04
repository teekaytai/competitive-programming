for _ in range(int(input())):
    X, Y = tuple(map(float, input().split()))
    a = [tuple(map(float, input().split())) for _ in range(int(input()))]
    print(['curse the darkness', 'light a candle'][any((X-x)**2+(Y-y)**2 <= 64 for x,y in a)])
