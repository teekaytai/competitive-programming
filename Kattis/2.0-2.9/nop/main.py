c = 0
t = 0
for x in input():
    if x.isupper(): t += -c % 4; c = 1
    else: c += 1
print(t)
