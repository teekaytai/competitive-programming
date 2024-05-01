n=int(input())
s=input()
print((s[0]=='1')+(n>1 and '1'in s[:2])+sum('1'in s[i:i+3]for i in range(n-3)))
