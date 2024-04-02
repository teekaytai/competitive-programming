a, b = map(int, input().split())
ans = []
for x in range(a, b+1):
    for y in range(x, b+1):
        if sorted(f'{x}{y}') == sorted(f'{x*y}'):
            ans.append(f'x = {x}, y = {y}, xy = {x*y}')
print(len(ans), 'digit-preserving pair(s)')
print('\n'.join(ans))
