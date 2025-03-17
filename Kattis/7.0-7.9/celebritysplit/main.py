def f(a):
    s = {0: 0}
    for x in a:
        s2 = {}
        for k, v in s.items():
            for k2, v2 in (abs(k - x), v), (abs(k + x), v), (k, v + x):
                s2[k2] = min(s2.get(k2, 1000000000), v2)
        s = s2
    return s
while n := int(input()):
    s1 = f([int(input()) for _ in range(n // 2)])
    s2 = f([int(input()) for _ in range((n + 1) // 2)])
    print(min(s2.get(k, 1000000000) + v for k, v in s1.items()))
