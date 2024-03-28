c = [0] * 4
s = input()
for x in s:
    if x.isalpha(): c[1 + x.isupper()] += 1
    else: c[3 * (x!='_')] += 1
for n in c:
    print(n / len(s))
