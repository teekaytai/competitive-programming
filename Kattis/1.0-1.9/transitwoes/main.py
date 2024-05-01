s, t, n = map(int, input().split())
*A, = map(int, input().split())
*B, = map(int, input().split())
*C, = map(int, input().split())
x = s + A[0]
for a,b,c in zip(A[1:],B,C):
    x = (x+c-1)//c*c
    x += b + a
print(['no','yes'][x <= t])
