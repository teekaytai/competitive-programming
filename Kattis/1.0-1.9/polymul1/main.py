for _ in range(int(input())):
    d1 = int(input())
    *c1, = map(int, input().split())
    d2 = int(input())
    *c2, = map(int, input().split())
    c = [0] * (d1+d2+1)
    for i in range(d1+1):
        for j in range(d2+1):
            c[i+j] += c1[i] * c2[j]
    print(d1+d2)
    print(*c)
