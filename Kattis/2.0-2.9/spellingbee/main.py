d = input()
for _ in range(int(input())):
    s = input()
    if len(s) > 3 and all(c in d for c in s) and d[0] in s: print(s)
