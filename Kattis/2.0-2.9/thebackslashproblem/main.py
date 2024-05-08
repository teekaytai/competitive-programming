*a, = open(0)
for x, s in zip(a[::2], a[1::2]):
    n = int(x)
    print(''.join('\\'*(2**n-1)+c if '!'<=c<='*' or '['<=c<=']' else c for c in s[:-1]))
