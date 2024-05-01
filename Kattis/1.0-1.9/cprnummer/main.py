a = [int(d) for d in input() if d.isdigit()]
c = [4, 3, 2, 7, 6, 5, 4, 3, 2, 1]
print(int(sum(x*y for x,y in zip(a, c)) % 11 == 0))
