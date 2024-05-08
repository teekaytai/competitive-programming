for _ in range(int(input())):
    s, d = map(int, input().split())
    if d > s or (s-d)%2: print('impossible')
    else: l = (s-d)//2; print(s-l, l)
