import re
a, s = input().split()
if a == 'E':
    print(''.join(m[0]+str(len(m)) for m, _ in re.findall(r'((.)\2*)', s)))
else:
    print(''.join(x*int(c) for x,c in zip(s[::2], s[1::2])))
