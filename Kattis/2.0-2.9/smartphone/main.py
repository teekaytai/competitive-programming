def f(s, t):
    m = min(len(s), len(t))
    for i in range(m):
        if s[i] != t[i]: return len(s) - i + len(t) - i
    return abs(len(t) - len(s))
for _ in range(int(input())):
    t = input()
    s = input()
    print(min(f(s, t), 1+f(input(), t), 1+f(input(), t), 1+f(input(), t)))
