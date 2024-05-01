for _ in range(int(input())):
    a,b,c = map(int, input().split())
    print(['Impossible','Possible'][c in (a+b,a-b,b-a,a*b,a/b,b/a)])
