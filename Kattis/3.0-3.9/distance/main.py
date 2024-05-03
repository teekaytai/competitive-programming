X = []
Y = []
for _ in range(n:=int(input())):
    x, y = map(int, input().split())
    X.append(x)
    Y.append(y)
X.sort()
Y.sort()
print(sum((X[i]+Y[i])*(i-(n-i-1)) for i in range(n)))
