a, b = input().split()
for i in range(len(a)):
    j = b.find(a[i])
    if j>=0: break
for r in range(len(b)):
    if r == j: print(a)
    else: print('.'*i+b[r]+'.'*(len(a)-i-1))
