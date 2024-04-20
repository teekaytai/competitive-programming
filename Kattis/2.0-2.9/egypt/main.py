while True:
    a, b, c = sorted(map(int, input().split()))
    if not a: break
    print(['wrong', 'right'][a*a+b*b==c*c])
