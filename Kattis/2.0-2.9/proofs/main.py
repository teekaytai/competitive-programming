s = set()
for i in range(1, int(input())+1):
    *a, _, c = input().split()
    if any(x not in s for x in a): print(i); break
    s.add(c)
else:
    print('correct')
