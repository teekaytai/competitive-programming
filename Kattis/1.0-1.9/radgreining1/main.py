n, m = map(int, input().split())
a = ['?'] * n
for _ in range(m):
    i, s = input().split()
    i = int(i) - 1
    for j, c in enumerate(s):
        if '?' != a[i+j] != c:
            print('Villa')
            exit()
        a[i+j] = c
print(''.join(a))
