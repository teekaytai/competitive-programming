s=input()
a,b,c=s.count('T'),s.count('C'),s.count('G')
print(7*min(a,b,c)+a*a+b*b+c*c)
