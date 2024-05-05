s = input()
n = len(s) // 3
print(''.join(sorted((a,b,c))[1] for a,b,c in zip(s[:n], s[n:2*n], s[2*n:])))
