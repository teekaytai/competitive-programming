x = int(input())
y = int(input())
print([2, 1][x > 0] if y > 0 else [3, 4][x > 0])
