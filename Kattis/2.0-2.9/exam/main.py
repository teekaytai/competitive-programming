k = int(input())
s = input()
t = input()
n = len(s)
v = sum(x==y for x,y in zip(s, t))
print(min(k, v) + n-v-max(k-v, 0))
