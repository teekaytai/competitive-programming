from itertools import zip_longest
a=input()
b=input()
s = ''
t = ''
for x,y in zip_longest(a[::-1], b[::-1], fillvalue='0'):
    if x >= y: s += x
    if y >= x: t += y
print(int(s[::-1]) if s else 'YODA')
print(int(t[::-1]) if t else 'YODA')
