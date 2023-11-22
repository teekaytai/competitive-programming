t = int(input())
A = []
for I in range(t):
    n = input()
    a = [int(x) for x in input().split()]
    c = float('inf')
    t = 0
    for x in reversed(a):
        if x > c:
            m = (x + c - 1) // c
            t += m - 1
            c = x // m
        else:
            c = x
    A.append(t)
print(*A, sep='\n')

