_, *a = open(0)
print(max((s for s in a if len(set(s))==len(s)>5), key=lambda s: (-len(s), s), default='Neibb'))
