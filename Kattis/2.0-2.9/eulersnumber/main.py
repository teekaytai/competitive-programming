t = 1
s = 1
for i in range(1, int(input())+1):
    t /= i
    s += t
print(s)
