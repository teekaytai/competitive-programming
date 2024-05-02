for _ in range(int(input())):
    n = int(input())
    mx = -float('inf')
    I = 0
    for i in range(1, n+1):
        a,b,c = map(int, input().split())
        m = c+(b*b/4/a)
        if m > mx:
            mx = m; I = i
    print(I)
