t = int(input())
for i in range(t):
    n, m = map(int, input().split())
    s = input()
    t = input()
    dup = [False, False]
    for i, c in enumerate(s):
        if i < len(s) - 1 and s[i + 1] == c:
            dup[int(c)] = True
    if not any(dup):
        print('Yes')
        continue
    t_dup = False
    for i, c in enumerate(t):
        if i < len(t) - 1 and t[i + 1] == c:
            t_dup = True
            break
    if t_dup:
        print('No')
        continue
    print('Yes' if (not dup[0] or t[0] == '1' and t[-1] == '1') and (not dup[1] or t[0] == '0' and t[-1] == '0') else 'No')