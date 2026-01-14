_,*a=map(int,open(0))
r=[]
i=m=1000
while i:
 s='';i-=1;v=i
 for x,c in zip([900,500,400,100,90,50,40,10,9,5,4,1],'CM D CD C XC L XL X IX V IV I'.split()):s+=v//x*c;v%=x
 r+=[(s,i)]
for x in a:q=x//m;i=[y for _,y in sorted(r)].index(x%m);print(~q*m*(i>945)+q*946+i)