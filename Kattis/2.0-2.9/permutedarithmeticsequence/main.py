f = lambda s: all(y-x==s[1]-s[0] for x,y in zip(s, s[1:]))
for _ in range(int(input())):
    _, *a = map(int, input().split())
    if f(a): print('arithmetic')
    elif f(sorted(a)): print('permuted arithmetic')
    else: print('non-arithmetic')
