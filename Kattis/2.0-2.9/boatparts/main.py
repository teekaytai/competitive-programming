n, m = map(int, input().split())
s = set()
for i in range(1, m+1):
    s.add(input())
    if len(s) == n: print(i); break
else:
    print('paradox avoided')
