n, m = map(int, input().split())
d = {}
for _ in range(n):
    s = input()
    t = s[0] + s[s.find(' ')+1]
    d[t] = s if t not in d else 'ambiguous'
for _ in range(m):
    print(d.get(input(),'nobody'))
