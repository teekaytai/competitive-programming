n, m = map(int, input().split())
a, b = map(int, input().split())
d = (a*n-b*m)/(n-m)
print(d if 0<=d<=100 else 'impossible')
