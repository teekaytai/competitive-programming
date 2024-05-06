s = input()
n = len(s)
for h in range(int(n**.5), 0, -1):
    if n%h==0: break
print(''.join(s[i::h] for i in range(h)))
