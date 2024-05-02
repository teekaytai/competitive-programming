n, m, q = map(int, input().split())
g = [input() for _ in range(n)]
s = {*range(n)}
for _ in range(q):
    x, y = input().split()
    s = {i for i in s if g[i][int(x)-1] == y}
if len(s) == 1:
    print('unique')
    print(s.pop()+1)
else:
    print('ambiguous')
    print(len(s))
