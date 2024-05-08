n = int(input())
s = input()
m = 0
w = 0
i = 0
while i < len(s):
    m += s[i] == 'M'
    w += s[i] == 'W'
    if abs(m-w) > n and (i == len(s)-1 or s[i+1]==s[i]): break
    i += 1
print(i)
