from functools import lru_cache
n = int(input()) - 1
def f(x):
    return x/n * f(x-1) + (n-x)/n * g(n+1-x, 0) if x > 1 else 1.0
@lru_cache(maxsize=None)
def g(x, y):
    if x>=n: return 1.0
    if x+y>n: return 0.0
    return x/n * g(x+y+1, 0) + (n-x-y)/n * g(x, y+1)
print(f(n-1))
