h,m,s = map(int, input().split(':'))
H,M,S = map(int, input().split(':'))
t = (3600*(H-h)+60*(M-m)+(S-s)) % 86400 or 86400
print(f'{t//3600:02}:{t%3600//60:02}:{t%60:02}')
