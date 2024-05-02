w, x = map(int, input().split())
*a, = map(int, input().split())
p = [[(), (0,0,0)], [(0,)], [(0,1), (-1,)], [(-1,-1), (1,)], [(0,0), (1,), (-1,0), (-1,)], [(0,0), (0,), (1,1), (-2,)], [(0,0), (2,), (0,-1), (0,)]]
t = 0
for l in p[x-1]:
    for i in range(w-len(l)):
        h, *H = a[i:i+len(l)+1]
        t += all(h+y==z for y,z in zip(l,H))
print(t)
