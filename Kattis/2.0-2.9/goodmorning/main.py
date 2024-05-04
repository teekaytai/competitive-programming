g = [{0,1,2,4,5,7,8}, {1}, {1,2}, {1,2,3}, {1,4}, {1,2,4,5}, {1,2,3,4,5,6}, {1,4,7}, {1,2,4,5,7,8}, {1,2,3,4,5,6,7,8,9}]
def f(x):
    p = x % 10
    while x:
        q = x % 10
        if q not in g[p]: return False
        p = q
        x //= 10
    return True
for _ in range(int(input())):
    x = int(input())
    i = 0
    while True:
        if f(x+i): print(x+i); break
        if f(x-i): print(x-i); break
        i += 1
