from collections import defaultdict

s = 'welcome to code jam'
d = defaultdict(list)
for x, y in zip(s, range(1, len(s)+1)):
    d[x].append(y)

for tc in range(1, int(input())+1):
    c = [0] * (len(s)+1)
    c[0] = 1
    for x in input():
        for i in d[x]:
            c[i] = (c[i] + c[i-1]) % 10000
    print(f'Case #{tc}: {c[-1]:04}')
