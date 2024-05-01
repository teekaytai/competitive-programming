import re
for _ in range(int(input())):
    s,y,_,_,Y,_,_,c = re.split('[ /]',input())
    print(s, 'eligible' if int(y)>2009 or int(Y)>1990 else 'ineligible' if int(c) > 40 else 'coach petitions')
