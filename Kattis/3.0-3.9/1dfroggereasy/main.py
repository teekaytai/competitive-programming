n, s, m = map(int, input().split())
s -= 1
*a, = map(int, input().split())
h = 0
while a[s] != m:
    h += 1
    a[s], s = 0, s + a[s]
    if s < 0: print('left'); print(h); break
    if s >= n: print('right'); print(h); break
    if a[s] == 0: print('cycle'); print(h); break
else:
    print('magic')
    print(h)
