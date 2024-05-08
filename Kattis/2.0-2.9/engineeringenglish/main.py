s = set()
for l in open(0):
    print(*((s.add(w.lower()) or w) if w.lower() not in s else '.' for w in l.split()))
