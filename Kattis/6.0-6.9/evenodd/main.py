l, r = map(int, input().split())
def f(x):
    i = 0
    while x != 1:
        i += 1
        x = x+1 if x%2 else x//2
    return i
def g(l, r):
    t = 0
    while l<=r and (l==1 or l % 2 == 0): t += f(l); l += 1
    if r >= l and r % 2 == 1: t += f(r); r -= 1
    if l < r: t += (r-l+1)//2*3 + 2*g((l+1)//2, r//2)
    return t % 1000000007

print(g(l, r))
