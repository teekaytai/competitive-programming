import re

b = input() == 'D'
v = '([AEIOUYaeiouy])'
for _ in range(int(input())):
    l = input()
    if b: print(re.sub(v, r'ub\1',l))
    else: print(re.sub('(?:u|U)b'+v,r'\1',l))
