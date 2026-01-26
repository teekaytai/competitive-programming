ans = []
for i in range(1, int(input()) + 1):
    n = int(input())
    t = 2000000000
    st = []
    for x in map(int, input().split()):
        if x > t:
            ans.append(i)
            break
        while st and st[-1] > x:
            t = st.pop()
        if not st or st[-1] != x:
            st.append(x)
print(len(ans))
for x in ans:
    print(x)
