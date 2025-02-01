a = input()
d='N NE E SE S SW W NW'.split()
print(d[(d.index(a) + 4) % 8])
