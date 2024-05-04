from collections import Counter
import re
s, n = input().split()
def f(s):
    a = re.split(r'(?<=.)(?=[A-Z])|(?<=[A-Z])(?=.)', s)
    i = 0
    c = Counter()
    while i < len(a):
        if i < len(a)-1 and a[i+1].isdigit():
            c[a[i]] += int(a[i+1])
            i += 2
        else:
            c[a[i]] += 1
            i += 1
    return c
c = f(s)
C = f(input())
print(min(c[k]*int(n)//v for k, v in C.items()))
