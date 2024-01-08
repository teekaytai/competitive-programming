n = int(input())
c = [8]*4
B = [False] * 2
for i in range(n):
    a,b,_,x = input()
    if a.isdigit():c[b=='+'] -= 1;B[0]|=x=='b'
    else: c[2 + (a=='+')] -= 1;B[1]|=x=='b'
print(0 if c[2]and c[3]and not B[1] else 1 if c[0]and c[1]and not B[0]else 2)
