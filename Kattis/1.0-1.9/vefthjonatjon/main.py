_, *a = open(0)
print(min(s.count('J') for s in zip(*map(str.split,a))))
