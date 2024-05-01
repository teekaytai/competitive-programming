s=input()
q=input()
print(''.join(s[int(q[i:i+3])-1]for i in range(0,len(q),3)))
