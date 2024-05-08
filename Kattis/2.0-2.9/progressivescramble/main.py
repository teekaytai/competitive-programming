from itertools import accumulate
K = ' abcdefghijklmnopqrstuvwxyz'
for _ in range(int(input())):
    s = input()
    if s[0] == 'e':
        print(''.join(K[x%27] for x in accumulate(map(K.find, s[2:]))))
    else:
        a = [0, *map(K.find, s[2:])]
        print(''.join(K[(y-x)%27] for x, y in zip(a, a[1:])))
