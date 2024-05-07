for _ in range(int(input())):
    t = input().split()
    s = set()
    while (l := input()) != 'what does the fox say?':
        s.add(l.split()[-1])
    print(' '.join(w for w in t if w not in s))
