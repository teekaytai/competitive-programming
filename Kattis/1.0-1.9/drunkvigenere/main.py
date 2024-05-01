c=input()
k=input()
print(''.join(chr((ord(x)-65+(-1)**(i+1)*(ord(y)-65))%26+65) for i,(x,y) in enumerate(zip(c,k))))
