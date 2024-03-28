from string import *
L = {*ascii_lowercase}
for _ in range(int(input())):
    d = L - {*input().lower()}
    print('missing', ''.join(sorted(d))) if d else print('pangram')
