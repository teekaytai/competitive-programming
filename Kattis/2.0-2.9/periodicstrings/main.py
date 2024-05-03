s = input()
n = len(s)
for i in range(1, n+1):
    if n%i: continue
    p = s[:i]
    for j in range(i, n, i):
        p = p[-1] + p[:-1]
        if s[j:j+i] != p:
            break
    else:
        print(i)
        break
