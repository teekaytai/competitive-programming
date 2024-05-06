for _ in range(int(input())):
    n = int(input())
    a = [int(input()) for _ in range(n)]
    m = max(a)
    if a.count(m) > 1: print('no winner')
    else: print(['minority', 'majority'][m>sum(a)//2], 'winner', a.index(m)+1)
