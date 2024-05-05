s = input()
a, b = 0, 1
for x in s:
    a, b = min(a+(x!='S'), b+(x!='N')+1), min(a+(x!='S')+1, b+(x!='N'))
print(min(a, b+1))
