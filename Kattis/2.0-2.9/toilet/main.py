a = input()
print(a.count('D')*2-(a[0]=='D')-2*(a[:2]=='DD'))
print(a.count('U')*2-(a[0]=='U')-2*(a[:2]=='UU'))
print(a.count('DU')+a.count('UD'))
