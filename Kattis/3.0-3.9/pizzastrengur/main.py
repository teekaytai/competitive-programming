import random
n = int(input())
a = []
def q():
    print(''.join(a), flush=True)
    return int(input())
l = ['A', 'I', 'P', 'Z']
for _ in range(n):
    random.shuffle(l)
    a.append(l[0])
    if q(): continue
    a[-1] = l[1]
    if q(): continue
    a[-1] = l[2]
    if not q(): a[-1] = l[3]
if a[-1] == l[-1]: q()
