s=set()
for _ in range(int(input())):
    a, b = input().split()
    if a == 'entry':
        print(*[b, 'entered'] + ['(ANOMALY)']*(b in s))
        s.add(b)
    else:
        print(*[b, 'exited'] + ['(ANOMALY)']*(b not in s))
        s.discard(b)
