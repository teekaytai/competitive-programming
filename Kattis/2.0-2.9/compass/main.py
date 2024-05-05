a, b = map(int, open(0))
print(min((b-a)%360, -((a-b)%360), key=abs))
