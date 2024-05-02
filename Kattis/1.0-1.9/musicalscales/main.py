input()
s={*input().split()}
A='A A# B C C# D D# E F F# G G#'.split()*2
B=[0,2,4,5,7,9,11]
ans=[]
for i in range(12):
    if not s - {A[i+j] for j in B}:ans.append(A[i])
print(*ans or ['none'])
