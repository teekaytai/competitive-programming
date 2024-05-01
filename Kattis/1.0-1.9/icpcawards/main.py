input()
s = set()
while len(s) < 12:
    a, b = input().split()
    if a not in s:
        print(a, b)
        s.add(a)
