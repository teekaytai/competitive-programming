tcs = int(input())
for tc in range(tcs):
    n = int(input())
    seen = set()
    s = input()
    t = 0
    for i, c in enumerate(s):
        if c not in seen:
            t += n - i
            seen.add(c)

    print(t)
