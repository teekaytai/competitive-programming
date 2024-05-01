x,y=0,0
for _ in range(3):
    X, Y = map(int, input().split())
    x^=X;y^=Y
print(x,y)
