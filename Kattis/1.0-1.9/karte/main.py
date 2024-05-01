from collections import Counter
c = Counter('PKHT'*13)
s=input()
if len(set(s[i:i+3]for i in range(0, len(s), 3))) < len(s)//3:
    print('GRESKA')
else:
    for i in range(0, len(s), 3):c[s[i]] -= 1
    print(c['P'], c['K'], c['H'], c['T'])
