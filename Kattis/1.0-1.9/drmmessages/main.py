s=[ord(c)-65 for c in input()]
n=len(s)
a=s[:n//2]
b=s[n//2:]
t=sum(a)
a=[(x+t)%26 for x in a]
t=sum(b)
b=[(x+t)%26 for x in b]
print(''.join(chr(65+(x+y)%26) for x,y in zip(a, b)))
