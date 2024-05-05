n = int(input())
a, b = 0, 0
for _ in range(n):
    x,y,z,w = map(int, input())
    a+=2-x-y
    b+=2-z-w
m = min(a,b)//2
print(m, a-2*m, b-2*m)
