d = {x^(x<<1)%256:x for x in range(256)}
input()
print(*map(d.get, map(int, input().split())))
