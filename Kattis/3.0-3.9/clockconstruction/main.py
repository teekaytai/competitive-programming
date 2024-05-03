n, h, w = map(int, input().split())
a = [[] for _ in range(h*w)]
for _ in range(n):
    for i in range(h):
        for j, c in enumerate(input()):
            a[w*i+j].append(c)
print(len(set(''.join(b for b in l) for l in a)))
