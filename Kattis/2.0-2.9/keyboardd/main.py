a = input()
b = input()
i = 0
s = set()
for j in range(len(b)):
    if i < len(a) and a[i] == b[j]:
        i += 1
    else:
        s.add(b[j])
print(''.join(s))
