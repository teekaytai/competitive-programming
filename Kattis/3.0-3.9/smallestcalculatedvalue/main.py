from itertools import product
a, b, c = input().split()
print(min(int(x) for o1, o2 in product('+-*/', repeat=2) if eval(s:=f'({a}{o1}{b}){o2}{c}') == (x := eval(s.replace('/', '//'))) and x >= 0))
