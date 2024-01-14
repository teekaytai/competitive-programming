from itertools import product
n = int(input())
for _ in range(n):
    x = int(input())
    for o1, o2, o3 in product(['+','-','*','//'], repeat=3):
        s = f'4 {o1} 4 {o2} 4 {o3} 4'
        if eval(s) == x:
            print(s.replace('//', '/'), '=', x)
            break
    else:
        print('no solution')
