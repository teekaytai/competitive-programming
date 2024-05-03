s=input()
print(min(s[j-1::-1] + s[i-1:j-1:-1] + s[:i-1:-1] for i in range(2, len(s)) for j in range(1, i)))
