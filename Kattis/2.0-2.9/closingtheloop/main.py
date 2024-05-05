for i in range(1, int(input())+1):
    n = int(input())
    b = []
    r = []
    for s in input().split():
        if s[-1]=='B': b.append(int(s[:-1]))
        else: r.append(int(s[:-1]))
    b.sort(reverse=True)
    r.sort(reverse=True)
    m = min(len(b), len(r))
    print(f'Case #{i}:', sum(b[:m]+r[:m])-m-m)
