n, *a = map(str.rstrip, open(0))
n = int(n)
d = [[] for _ in range(16)]
for w in a[:n]:
    d[len(w)].append(w)
def f(s, w, i=0, c=3):
    while i < len(s):
        if s[i] == w[i]:
            i += 1
            continue
        if not c:
            return False
        if w[i].isdigit() and f(s, w, i + 1, c - 1):
            return True
        for j in range(1, c + 1):
            if i + j < len(s):
                w[i], w[i+1:i+j+1] = w[i + j], w[i:i+j]
                if f(s, w, i, c - j):
                    return True
                w[i + j], w[i:i+j] = w[i], w[i+1:i+j+1]
        return False
    return True
for w in a[n:]:
    l = list(w)
    if not any(f(s, l) for s in d[len(w)]):
        print(w)
