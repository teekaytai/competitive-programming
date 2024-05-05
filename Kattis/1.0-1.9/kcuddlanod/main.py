x, y = map(int, input()[::-1].replace('2','.').replace('5','2').replace('.','5').split())
print(1+(x>y))
