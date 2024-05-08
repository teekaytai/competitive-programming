_, *a = map(int, open(0))
a.sort()
print(sum(a)-sum(a[-3::-3]))
