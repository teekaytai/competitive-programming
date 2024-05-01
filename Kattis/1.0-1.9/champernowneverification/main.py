s=input()
i = 0
k = 0
while i < len(s):
    k += 1
    for c in str(k):
        if s[i] != c:
            print(-1)
            exit()
        i += 1
print(k)
