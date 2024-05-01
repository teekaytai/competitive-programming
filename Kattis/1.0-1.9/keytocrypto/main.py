a=[ord(x)-65 for x in input()]
k=[ord(x)-65 for x in input()]
n=len(k)
for x,y in zip(a,k):
    k.append((x-y)%26)
print(''.join(chr(x+65)for x in k[n:]))
