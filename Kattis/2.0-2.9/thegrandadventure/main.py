for _ in range(int(input())):
    s = []
    for c in input():
        if c == '.': continue
        if c in '$|*': s.append(c)
        elif not s or s[-1] != {'b':'$','t':'|','j':'*'}[c]: print('NO'); break
        else: s.pop()
    else:
        print(['NO', 'YES'][not s])
