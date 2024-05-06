_, *a = map(str.strip, open(0))
print(''.join(w[::-1] for w in a[::-1]))
