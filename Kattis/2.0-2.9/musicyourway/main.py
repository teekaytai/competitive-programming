from operator import itemgetter
ks = input().split()
a = [dict(zip(ks, input().split())) for _ in range(int(input()))]
for _ in range(int(input())):
    print(*ks)
    a.sort(key=itemgetter(input()))
    for d in a:
        print(*d.values())
    print()
