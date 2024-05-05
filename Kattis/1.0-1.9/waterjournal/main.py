n, a, b = map(int, input().split())
x = 0
y = 0
r = 1
for _ in range(n-1):
    v = int(input())
    if v == a: x = 1
    if v == b: y = 1
    if v < a or v > b: r = 0
if not r or x+y==0: print(-1)
elif x==y: print(*range(a,b+1), sep='\n')
else: print(b if x else a)
