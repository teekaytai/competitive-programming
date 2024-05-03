n, q = map(int, input().split())
A = [(0, 0)]*(n+1)
v = 0, 0
for z in range(q):
    c, *x = input().split()
    if c == 'SET': A[int(x[0])] = z, int(x[1])
    elif c == 'PRINT': print(max(A[int(x[0])], v)[1])
    else: v = z, int(x[0])
