n, *a = map(int, open(0).read().split())
g = [[] for _ in range(n + 1)]
for i, x in enumerate(a):
    g[x].append(i)
ans = []
st = []
for i, x in enumerate(a):
    if st and st[-1] == i:
        st.pop()
    elif st and st[-1] < g[x][-1]:
        print('IMPOSSIBLE')
        exit()
    else:
        ans.append((g[x][0] + 1, g[x][-1] + 1, x))
        st += reversed(g[x])
        st.pop()
print(len(ans))
for t in ans:
    print(*t)
