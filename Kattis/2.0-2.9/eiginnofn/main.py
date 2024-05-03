d = {}
for _ in range(int(input())):
    f, *l = input().split()
    d[f] = l[0] if l else False
for _ in range(int(input())):
    a = d.get(k:=input())
    if a is None: print('Neibb')
    elif not a: print('Jebb')
    else: print(f'Neibb en {k} {a} er heima')
