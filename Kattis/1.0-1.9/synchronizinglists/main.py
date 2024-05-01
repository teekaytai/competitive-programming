while n:=int(input()):
    a=[int(input())for _ in range(n)]
    b=sorted(int(input())for _ in range(n))
    I = sorted(range(n),key=a.__getitem__)
    c = [0]*n
    for i, x in zip(I, b): c[i] = x
    for x in c: print(x)
