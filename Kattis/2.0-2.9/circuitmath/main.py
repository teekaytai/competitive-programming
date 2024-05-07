n = int(input())
a = {l: c == 'T' for l, c in zip('ABCDEFGHIJKLMNOPQRSTUVWXYZ', input().split())}
s = []
for c in input().split():
    if c.isalpha():
        s.append(a[c])
    elif c == '+':
        s.append(s.pop() | s.pop())
    elif c == '*':
        s.append(s.pop() & s.pop())
    else:
        s[-1] = not s[-1]
print(str(s[-1])[0])
