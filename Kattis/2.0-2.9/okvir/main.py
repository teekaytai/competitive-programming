h, w = map(int, input().split())
u, l, r, d = map(int, input().split())
g = [['#.'[(i+j) % 2] for j in range(w+l+r)] for i in range(h+u+d)]
for i in range(u, u+h):
    g[i][l:l+w] = input()
for row in g: print(''.join(row))
