n = int(input())
s = input()[::-1]
t = 0
r = False
for i, c in enumerate(s):
    if i < n-1 and c==s[i+1] and (c=='B')^r:
        r = not r
        t += 1
    elif (c=='B')^r: t += 1
print(t)
