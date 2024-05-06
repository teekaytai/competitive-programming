a = [tuple(map(int, l.split())) for l in open(0)]
print(next((i for i, d in enumerate(a, start=1) if all(i==j or any(v!=w for v in d for w in d2) and sum((x>y)-(y>x) for x in d for y in d2) >= 0 for j, d2 in enumerate(a, start=1))), 'No dice'))
