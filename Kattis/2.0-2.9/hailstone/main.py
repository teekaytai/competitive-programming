s = x = int(input())
while x > 1: x = [x//2,3*x+1][x%2]; s += x
print(s)
