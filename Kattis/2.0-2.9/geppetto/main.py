n, m = map(int, input().split())
g = [[] for _ in range(n)]
for _ in range(m):
    u, v = sorted(map(int, input().split()))
    u -= 1; v -= 1
    g[v].append(u)

used = [False] * n
def f(i):
    if i == n:
        return 1
    s = f(i+1)
    if not any(used[j] for j in g[i]):
        used[i] = True
        s += f(i+1)
        used[i] = False
    return s
print(f(0))
