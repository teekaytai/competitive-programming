for _ in range(int(input())):
    p, r, f = map(int, input().split())
    i = 0
    while p <= f: i+=1; p *= r
    print(i)
