c, n = map(int, input().split())
v = 0
res = 'possible'
for _ in range(n):
    x, y, z = map(int, input().split())
    if x > v: res = 'impossible'
    v += y - x
    if v > c: res = 'impossible'
    if z and v != c: res = 'impossible'
if v or y or z: res = 'impossible'
print(res)
