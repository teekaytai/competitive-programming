n = int(input())
s = input()
for i in range(n, 1, -1):
    print(f'{i} bottles of {s} on the wall, {i} bottles of {s}.')
    print(f'Take one down, pass it around, {i-1} bottle{"s"*(i>2)} of {s} on the wall.')
    print()
print(f'1 bottle of {s} on the wall, 1 bottle of {s}.')
print(f'Take it down, pass it around, no more bottles of {s}.')
