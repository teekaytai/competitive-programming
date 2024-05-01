s=input()
p=input()
q=p[:len(set(s))+9]
print('LOSE'if any(c not in q for c in s)else'WIN')
