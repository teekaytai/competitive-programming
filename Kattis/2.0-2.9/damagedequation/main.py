a, b, c, d = map(int, input().split())
O = ['*', '+', '-', '//']
ans = []
for o1 in O:
    for o2 in O:
        try:
            if eval(f'{a}{o1}{b}=={c}{o2}{d}'):
                ans.append(f'{a} {o1[:1]} {b} = {c} {o2[:1]} {d}')
        except: pass
if not ans: print('problems ahead')
for x in ans: print(x)
