s = input()
t = input()
print(len(s)+len(t)-2*next((i for i,(x,y) in enumerate(zip(s, t)) if x!=y), min(len(s), len(t))))
