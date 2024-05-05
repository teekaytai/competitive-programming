p = 1
for _ in range(int(input())):
    x, o, y = input().split()
    x = int(x)
    y = int(y)
    if o == '+': p = x+y-p
    if o == '-': p *= x-y
    if o == '*': p = (x*y)**2
    if o == '/': p = (x+1)//2
    print(p)
